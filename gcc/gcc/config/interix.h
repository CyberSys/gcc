/* Operating system specific defines to be used when targeting GCC for
   Interix
   Copyright (C) 1994, 1995, 1999, 2002, 2004, 2007, 2010
   Free Software Foundation, Inc.
   Donn Terry, Softway Systems, Inc. (donn@softway.com)
   Modified from code
      Contributed by Douglas B. Rupp (drupp@cs.washington.edu).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* POSIX/Uni-thread only for now.  Look at the winnt version
for windows/multi thread */

/* We need multiple -lc -lcpsx because they mutually refer;
   that should go away someday */

#undef LIB_SPEC
#define LIB_SPEC "\
 %{!shared:%{!dynamic:-lc -lcpsx -lc -lcpsx %$INTERIX_ROOT/usr/lib/psxdll.a \
 %$INTERIX_ROOT/usr/lib/psxdll2.a \
 }} \
 %{!G:%{!dynamic:-lc -lcpsx -lc -lcpsx %$INTERIX_ROOT/usr/lib/psxdll.a \
 %$INTERIX_ROOT/usr/lib/psxdll2.a \
 }} \
 %{dynamic:-lc %$INTERIX_ROOT/usr/lib/psxdll.a \
 %$INTERIX_ROOT/usr/lib/psxdll2.a \
 } \
 %{v}"

#undef LINK_SPEC
#define LINK_SPEC "%{!shared:-stack 0x400000,0x10000} \
 		   -subsystem posix \
		   %{g} \
		   %{dynamic:-Bdynamic} \
		   %{static:-Bstatic} \
		   %{shared:--shared -Bdynamic} \
		   %{G:--shared -Bdynamic} \
		   %{symbolic:--shared -Bsymbolic -Bdynamic} \
   		   %{rpath*:--rpath %*} \
		   "

#undef STARTFILE_SPEC
#define STARTFILE_SPEC  \
  "%{!shared:%{pg:gcrt0%O%s}%{!pg:%{p:mcrt0%O%s}%{!p:crt0%O%s}}} %{shared:crti%O%s}"


#define STDC_0_IN_SYSTEM_HEADERS 1

/* Names to predefine in the preprocessor for this target machine.  */

#define DBX_DEBUGGING_INFO 1
#define SDB_DEBUGGING_INFO 1
#undef PREFERRED_DEBUGGING_TYPE
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG


/* TARGET_DEFAULT from configure */

#undef WCHAR_TYPE
#undef WCHAR_TYPE_SIZE
#define WCHAR_TYPE "short unsigned int"
#define WCHAR_TYPE_SIZE 16

/* Our strategy for finding global constructors is a bit different, although
   not a lot.  */
#define DO_GLOBAL_CTORS_BODY						\
do {									\
  int i;								\
  unsigned long nptrs;							\
  func_ptr *p;								\
  asm(									\
       "     .section .ctor_head, \"rw\"\n"				\
       "1:\n"								\
       "     .text \n"							\
       ASM_LOAD_ADDR(1b,%0)						\
       : "=r" (p) : : "cc");						\
  for (nptrs = 0; p[nptrs] != 0; nptrs++);				\
  for (i = nptrs-1; i >= 0; i--)					\
    p[i] ();								\
} while (0) 

#define DO_GLOBAL_DTORS_BODY						\
do {									\
  func_ptr *p;								\
  asm(									\
       "     .section .dtor_head, \"rw\"\n"				\
       "1:\n"								\
       "     .text \n"							\
       ASM_LOAD_ADDR(1b,%0)						\
       : "=r" (p) : : "cc");						\
  while (*p)								\
    {									\
      p++;								\
      (*(p-1)) ();							\
    }									\
} while (0) 
