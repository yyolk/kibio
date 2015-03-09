// =============================================================================
//
// Copyright (c) 2015 Brannon Dorsey <http://brannondorsey.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once
#include "ofMain.h"

namespace Kibio {
    
/// \brief Enum for all UserInterface button types
enum UIButtonType {
    BUTTON_OPEN_PROJECT,
    BUTTON_NEW_PROJECT,
    BUTTON_SAVE_PROJECT,
    BUTTON_INFO,
    BUTTON_TOGGLE_MODE,
    BUTTON_TOOL_BRUSH,
    BUTTON_TOOL_TRANSLATE,
    BUTTON_TOOL_ROTATE,
    BUTTON_TOOL_SCALE
};
    
/// \brief A user interface event class
class UserInterfaceEvent : public ofEventArgs
{
public:
    UserInterfaceEvent(UIButtonType _type):
    type(_type){};
    
    UIButtonType type;
};
    
/// \brief A an image button
class ImageButton
{
public:
    ImageButton(const std::string& imagePath,
                UIButtonType _type,
                ofColor color,
                ofColor highlightColor,
                ofColor shadowColor);
    
    ~ImageButton();
    
    void set(int x, int y, int width, int height);
    void update(const ofPoint& mouse);
    void draw(const ofPoint& shadowOffset=ofPoint::zero());
    
    void select();
    void unselect();
    void setSelected(bool b);
    
    bool isSelected();
    bool isHovered();
    
    UIButtonType type;
    
protected:
    
    bool _bSelected;
    bool _bHovered;
    
    ofColor _color;
    ofColor _highlightColor;
    ofColor _shadowColor;
    ofTexture _texture;
    ofRectangle _rect;
};

/// \brief A class for managing the user interface
class UserInterface
{
public:
    
    UserInterface();
    ~UserInterface();
    
    void update();
    void draw();
    
    void placeIcons();
    void toggleVisible();
    void hide();
    void show();
    
    void setProjectName(const std::string& name);
    void setDrawIconShadows(bool drawIconShadows);
    
    bool isVisible() const;
    
    ofEvent<UserInterfaceEvent> buttonEvent;

protected:

    bool _bDrawIconShadows;
    bool _bVisible;
    
    int _iconPadding;
    int _iconSize;
    
    std::string _projectName;
    
    ofVec2f _shadowOffset;
    
    ofColor _color;
    ofColor _highlightColor;
    ofColor _shadowColor;

    ImageButton _openProjectButton;
    ImageButton _newProjectButton;
    ImageButton _saveProjectButton;
    ImageButton _infoButton;
    ImageButton _toggleModeButton;
    ImageButton _toolBrushButton;
    ImageButton _toolTranslateButton;
    ImageButton _toolRotateButton;
    ImageButton _toolScaleButton;
    
};
    
} // namespace Kibio