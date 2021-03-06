#include "hudClass.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "gamedata.h"
#include "aaline.h"

HudClass& HudClass::getInstance(){
    static HudClass instance;
    return instance;
}

HudClass::HudClass():
    hudWidth(Gamedata::getInstance().getXmlInt("hudBar/width")),
    hudHeight(Gamedata::getInstance().getXmlInt("hudBar/height")),
    xPos(Gamedata::getInstance().getXmlInt("hudBar/startLoc/x")),
    yPos(Gamedata::getInstance().getXmlInt("hudBar/startLoc/y")),
    rgbVal(Gamedata::getInstance().getXmlInt("hudBar/color/red"),
           Gamedata::getInstance().getXmlInt("hudBar/color/blue"),
           Gamedata::getInstance().getXmlInt("hudBar/color/green"))
{}

HudClass::~HudClass()
{}

void HudClass::drawHud(SDL_Surface* const screen, const IOmod& io, int seconds, int fps) const{

    const Uint32 color = SDL_MapRGB(screen->format, rgbVal.red, rgbVal.blue, rgbVal.green);
    Draw_AALine(screen, xPos, yPos+hudHeight/2, xPos+hudWidth, yPos+hudHeight/2, hudHeight, 0, 0, 0, 0xff/2);
    io.writeText("Press:", xPos+5, yPos+5);
    io.writeText("A -> LEFT   D-> RIGHT   ", xPos+10, yPos+30);
    io.writeText("W -> UP     S -> DOWN   ", xPos+10, yPos+52);
    io.writeText("K -> BOOST  HEALTH    ", xPos+10, yPos+72);
    Draw_AALine(screen, xPos, yPos, xPos + hudWidth, yPos, color);
    Draw_AALine(screen, xPos, yPos+hudHeight, xPos + hudWidth, yPos+hudHeight, color);
}

