#ifndef GUI_H
#define GUI_H

#include "engine.h"

enum EAlign
{
    AlignLeft,
    AlignRight,
    AlignCenter
};

class GUI: public Renderable
{
    static sf::RenderTarget* renderTarget;
    static sf::Vector2f mousePosition;
    static int mouse_click;
    static int mouse_down;
    bool init;
public:
    GUI();

    virtual void render(sf::RenderTarget& window);

    virtual void onGui() = 0;

    static void text(sf::FloatRect rect, string text, EAlign align = AlignLeft, float textSize = 30);
    static bool button(sf::FloatRect rect, string text, float textSize = 30);
    static bool toggleButton(sf::FloatRect rect, bool active, string textValue, float fontSize = 30);
    static float vslider(sf::FloatRect rect, float value, float minValue, float maxValue);
    static sf::RenderTarget* getRenderTarget() { return renderTarget; }
};

class MouseRenderer : public Renderable
{
public:
    bool visible;

    MouseRenderer();

    virtual void render(sf::RenderTarget& window);
};

#endif//GUI_H
