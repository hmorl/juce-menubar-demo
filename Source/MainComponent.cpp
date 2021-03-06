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
    
    m_menuBar.addListener (this);
    
    #if JUCE_MAC
     MenuBarModel::setMacMainMenu (&m_menuBar);
    #endif
    
    m_buttonOne.setButtonText ("Button 1");
    m_buttonOne.setClickingTogglesState (true);
    addAndMakeVisible (m_buttonOne);
    
    m_buttonTwo.setButtonText ("Button 2");
    m_buttonTwo.setClickingTogglesState (true);
    addAndMakeVisible (m_buttonTwo);
}

MainComponent::~MainComponent()
{
    m_menuBar.removeListener (this);
    
    #if JUCE_MAC
     MenuBarModel::setMacMainMenu (nullptr);
    #endif
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

void MainComponent::menuBarItemsChanged (juce::MenuBarModel *menuBarModel)
{}

void MainComponent::menuCommandInvoked (juce::MenuBarModel *menuBarModel,
                                        const ApplicationCommandTarget::InvocationInfo &info)
{}

void MainComponent::menuBarActivated (MenuBarModel* menuBarModel, bool isActive)
{
    std::cout << "Menu bar " << (isActive ? "activated" : "deactivated") << std::endl;

    if (isActive)
    {
        m_menuBar.setComponentToReturnFocusTo (getCurrentlyFocusedComponent());
        unfocusAllComponents();
    }
}
