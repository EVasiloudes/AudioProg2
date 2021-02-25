//
//  Oscillators.h
//  Week4MoreClasses
//
//  Created by tmudd on 03/02/2020. edited by s1766312
//  Copyright Â© 2020 tmudd. All rights reserved.
//

#ifndef Oscillators_h
#define Oscillators_h

// BASE class - a basic phasor
class Phasor
{
public:
    
    // Our parent oscillator class does the key things required for most oscillators:
    // -- handles phase
    // -- handles setters and getters for frequency and samplerate
    
    /// update the phase and output the next sample from the oscillator
    float process()
    {
        phase += phaseDelta;
        
        if (phase > 1.0f)
            phase -= 1.0f;
        
        return output(phase);
    }
    
    /// this function is the one that we will replace in the classes that inherit from Phasor
    virtual float output(float p)
    {
        return p;
    }
    
    void setSampleRate(float sr)
    {
        sampleRate = sr;
    }
    
    void setFrequency(float freq)
    {
        frequency = freq;
        phaseDelta = frequency / sampleRate;
    }
    
private:
    float frequency;
    float sampleRate;
    float phase = 0.0f;
    float phaseDelta;
};

// CHILD Class
class TriOsc : public Phasor
{
    // redefine (override) the output function so that we can return a different function of the phase (p)
    float output(float p) override
    {
        return fabsf(p - 0.5f) - 0.5f;
    }
};

// CHILD Class
class SineOsc : public Phasor
{
    // redefine (override) the output function so that we can return a different function of the phase (p)
    float virtual output(float p) override
    {
        return sin(p * 2.0f * 3.141592653589793f);
    }
};

// CHILD Class
class SquareOsc : public Phasor
{
    // redefine (override) the output function so that we can return a different function of the phase (p)
    float virtual output(float p) override
    {
        // calculate the square wave
        float sqVal = 1.0f;
        if (p < 0.5f)
            sqVal = -1.0f;
        
        // return the squareValue
        return sqVal * 0.125f;
    }
};
#endif /* Oscillators_h */
