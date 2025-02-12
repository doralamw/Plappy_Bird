#pragma once
#include "Button.h"
#include "Common_Funtions.h"

class Button;
class Menu : public BaseObject {
private:
public:
	Button* button[4];
	static enum buttonNames { PLAY, QUIT, HELP, SOUND };
	Menu();
	bool selectButton(SDL_Event* e);
	void Draw(SDL_Renderer* ren) override;
	void initMenu(SDL_Renderer* ren);
	~Menu();
};