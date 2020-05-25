/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DemoMenuBar   : public MenuBarModel
{
public:
    DemoMenuBar() {};
    ~DemoMenuBar() {};

    void setComponentToReturnFocusTo (Component* component)
    {
        m_componentToReturnFocusTo = component;
    };
    
    juce::StringArray getMenuBarNames() override
    {
        return StringArray ("File", "Edit");
    };

    juce::PopupMenu getMenuForIndex (int topLevelMenuIndex,
                                     const juce::String &menuName) override
    {
        juce::PopupMenu menu;
        
        menu.addItem (1, "Menu item 1");
        menu.addItem (2, "Menu item 2");
        menu.addItem (3, "Menu item 3");

        return menu;
    };

    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override
    {
        std::cout << "Menu item with ID " << menuItemID << " selected" << std::endl;
        
        if(m_componentToReturnFocusTo != nullptr)
            m_componentToReturnFocusTo->grabKeyboardFocus();
    };
    
private:
    Component* m_componentToReturnFocusTo {nullptr};
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public MenuBarModel::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    void menuBarItemsChanged (juce::MenuBarModel *menuBarModel) override;
    
    void menuCommandInvoked (juce::MenuBarModel *menuBarModel,
                             const ApplicationCommandTarget::InvocationInfo &info) override;
    
    void menuBarActivated (MenuBarModel* menuBarModel, bool isActive) override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    DemoMenuBar m_menuBar;
    
    juce::TextButton m_buttonOne;
    juce::TextButton m_buttonTwo;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
