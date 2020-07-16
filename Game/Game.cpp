

#include <iostream>
#include "core.h" 
#include "Math/Math.h"
#include "Math/Random.h"
#include "Math/Color.h"
#include "Math/Shape.h"
#include <string>
#include "Math/Transform.h"
#include "Object/Actor.h"
#include "Actors/Enemy.h"
#include "Actors/Player.h"

float thrust{ 300 };
nc::Vector2 velocity;

Player player;
Enemy enemy;

float frametime;
float roundtime{0};
bool gameOver{ false };

DWORD prevTime;
DWORD deltaTime;


bool Update(float dt) // delta time 60fps (1/60 = .016) (60 * 0.016 = 1) 
{ 
	frametime = dt;

	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);
	
	player.Update(dt);
	//enemy stuff
	enemy.Update(dt);

	
	return quit;
}

void Draw(Core::Graphics& graphics)
{
	graphics.DrawString(10, 10, std::to_string(frametime).c_str());
	graphics.DrawString(10, 20, std::to_string(1/frametime).c_str());
	graphics.DrawString(10, 30, std::to_string(deltaTime/1000.0f).c_str());

	if (gameOver) graphics.DrawString(400, 300, "Game Over");



	player.Draw(graphics);
	enemy.Draw(graphics);
}
int main() 
{
	DWORD ticks = GetTickCount(); //how many ticks in a second
	std::cout << ticks / 1000 / 60 / 60 << std::endl;
	prevTime = GetTickCount();

	player.Load("player.txt");
	enemy.Load("enemy.txt");
	enemy.SetTarget(&player);
	

	char name[] = "pog";
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw); 
	Core::GameLoop();
	Core::Shutdown(); 
}
