/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    m_buttonOne.setButtonText ("Button 1");
    m_buttonOne.setClickingTogglesState (true);
    addAndMakeVisible (m_buttonOne);
    
    m_buttonTwo.setButtonText ("Button 2");
    m_buttonTwo.setClickingTogglesState (true);
    addAndMakeVisible (m_buttonTwo);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // Fill the background
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // The bounds of the buttons are just hardcoded for the purposes of the demo
    m_buttonOne.setBounds (100, 100, 80, 50);
    m_buttonTwo.setBounds (400, 300, 80, 50);
}
}
