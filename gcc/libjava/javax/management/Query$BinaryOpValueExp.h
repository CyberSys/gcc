
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_management_Query$BinaryOpValueExp__
#define __javax_management_Query$BinaryOpValueExp__

#pragma interface

#include <javax/management/QueryEval.h>
extern "Java"
{
  namespace javax
  {
    namespace management
    {
        class ObjectName;
        class Query$BinaryOpValueExp;
        class ValueExp;
    }
  }
}

class javax::management::Query$BinaryOpValueExp : public ::javax::management::QueryEval
{

public:
  Query$BinaryOpValueExp(jint, ::javax::management::ValueExp *, ::javax::management::ValueExp *);
  ::javax::management::ValueExp * apply(::javax::management::ObjectName *);
  ::java::lang::String * toString();
private:
  static const jlong serialVersionUID = 1216286847881456786LL;
  jint __attribute__((aligned(__alignof__( ::javax::management::QueryEval)))) op;
  ::javax::management::ValueExp * exp1;
  ::javax::management::ValueExp * exp2;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_management_Query$BinaryOpValueExp__
