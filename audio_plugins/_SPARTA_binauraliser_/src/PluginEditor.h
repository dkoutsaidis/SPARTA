/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "inputCoordsView.h"
#include "pannerView.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor,
                      public Timer,
                      private FilenameComponentListener,
                      public ComboBox::Listener,
                      public Slider::Listener,
                      public Button::Listener
{
public:
    //==============================================================================
    PluginEditor (PluginProcessor* ownerFilter);
    ~PluginEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    PluginProcessor* hVst;
    void timerCallback() override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer<OpenGLGraphicsContextCustomShader> shader;
    OpenGLContext openGLContext;

    /* source coordinates viewport */
    ScopedPointer<Viewport> sourceCoordsVP;
    inputCoordsView* sourceCoordsView_handle;

    FilenameComponent fileChooser;

    /* sofa file loading */
    void filenameComponentChanged (FilenameComponent*) override  {
        String directory = fileChooser.getCurrentFile().getFullPathName();
        const char* new_cstring = (const char*)directory.toUTF8();
        binauraliser_setSofaFilePath(hVst->hBin, new_cstring);
    }

    /* panning window */
    ScopedPointer<pannerView> panWindow;
    bool refreshPanViewWindow;



    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> CBsourceDirsPreset;
    ScopedPointer<Slider> SL_num_sources;
    ScopedPointer<Label> label_N_dirs;
    ScopedPointer<Label> label_HRIR_len;
    ScopedPointer<Label> label_HRIR_fs;
    ScopedPointer<ToggleButton> TBuseDefaultHRIRs;
    ScopedPointer<Label> label_DAW_fs;
    ScopedPointer<ToggleButton> TB_showInputs;
    ScopedPointer<ToggleButton> TB_showOutputs;
    ScopedPointer<Slider> SL_pValue;
    ScopedPointer<Label> label_N_Tri;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
