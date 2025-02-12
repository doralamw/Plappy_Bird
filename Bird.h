#ifndef BIRD_H_
#define BIRD_H_

#include "Common_Funtions.h"

class Bird : public BaseObject {
private:
	int width;
	int height;

	float bird_pos;
	double jumpHeight;
	float speed;
	double jumpTimer;
	double lastJump;

	bool Jumpping;
	bool playing;
	bool birdDie;

	//BaseObject b0, b1, b2; 
public:
	Bird();
	~Bird();
	//void SetClip(BaseObject b0, BaseObject b1, BaseObject b2, SDL_Renderer* ren);
	void update();
	void HandleInput(SDL_Event e);

	void Draw(SDL_Renderer* ren) override;
	void Jump();
	double GetTimeJump();

	bool PlayerIsPlaying();

	bool checkCollision(SDL_Rect Object);

	void gameOver();

	bool checkBirdDie();
};
#endif // !BIRD_H_
