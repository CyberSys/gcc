
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_sound_midi_dssi_DSSISynthesizer$DSSIMidiChannel__
#define __gnu_javax_sound_midi_dssi_DSSISynthesizer$DSSIMidiChannel__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace sound
      {
        namespace midi
        {
          namespace dssi
          {
              class DSSISynthesizer;
              class DSSISynthesizer$DSSIMidiChannel;
          }
        }
      }
    }
  }
}

class gnu::javax::sound::midi::dssi::DSSISynthesizer$DSSIMidiChannel : public ::java::lang::Object
{

public:
  DSSISynthesizer$DSSIMidiChannel(::gnu::javax::sound::midi::dssi::DSSISynthesizer *, jint);
  virtual void noteOn(jint, jint);
  virtual void noteOff(jint, jint);
  virtual void noteOff(jint);
  virtual void setPolyPressure(jint, jint);
  virtual jint getPolyPressure(jint);
  virtual void setChannelPressure(jint);
  virtual jint getChannelPressure();
  virtual void controlChange(jint, jint);
  virtual jint getController(jint);
  virtual void programChange(jint);
  virtual void programChange(jint, jint);
  virtual jint getProgram();
  virtual void setPitchBend(jint);
  virtual jint getPitchBend();
  virtual void resetAllControllers();
  virtual void allNotesOff();
  virtual void allSoundOff();
  virtual jboolean localControl(jboolean);
  virtual void setMono(jboolean);
  virtual jboolean getMono();
  virtual void setOmni(jboolean);
  virtual jboolean getOmni();
  virtual void setMute(jboolean);
  virtual jboolean getMute();
  virtual void setSolo(jboolean);
  virtual jboolean getSolo();
public: // actually package-private
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) channel;
  ::gnu::javax::sound::midi::dssi::DSSISynthesizer * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_sound_midi_dssi_DSSISynthesizer$DSSIMidiChannel__
