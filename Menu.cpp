#include "Menu.h"

Menu::Menu() {
	button[PLAY] = new Button(0, 0);
	button[QUIT] = new Button(100, 120);
	button[HELP] = new Button(140, 129);
	button[SOUND] = new Button(200, 231);

	/*button[PLAY]->setPosition(230, 450);
	button[QUIT]->setPosition(241, 587);
	button[HELP]->setPosition(145, 278);
	button[SOUND]->setPosition(245, 100);*/
}

bool Menu::selectButton( SDL_Event* e) {
	while (true) {
		for (Button* b : button) {
			b->handleIntersection(e);
		}
		while (SDL_PollEvent(e)) {
			switch (e->type) {
			case SDL_MOUSEBUTTONDOWN:
				if (e->button.state == SDL_BUTTON_LEFT) {
					if (button[PLAY]->intersect)
						return true;
					if (button[QUIT]->intersect) {
						return false;
					}
				}
				break;
			}
		}
	}
}

void Menu::Draw(SDL_Renderer* ren) {
	for (int i = 0; i < 2; i++) {
		SDL_Rect dst = button[i]->GetDest();
		SDL_RenderCopy(ren, button[i]->GetTexture(), NULL,&dst );
	}
}

Menu::~Menu() {
	delete button[PLAY];
	delete button[QUIT];
}

void Menu::initMenu(SDL_Renderer* ren) {
	button[PLAY]->CreateTexture("IMG\play.png", ren);
	button[QUIT]->CreateTexture("IMG\play.png", ren);
}