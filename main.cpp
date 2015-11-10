
#include "sfwdraw.h"
#include "Header.h"




void main()
{
	sfw::initContext(800, 600, "NSFW Draw");

	unsigned enemy = sfw::loadTextureMap("./textures/enemyship.png", 9, 1);
	unsigned d = sfw::loadTextureMap("./textures/playership.png", 8, 1);
	unsigned bullet = sfw::loadTextureMap("./textures/bullet.png");
	unsigned r = sfw::loadTextureMap("./textures/space800x600.jpg");
	unsigned asb = sfw::loadTextureMap("./textures/asteroidbelt.png");
	unsigned neb = sfw::loadTextureMap("./textures/nebula.png");
	unsigned u = sfw::loadTextureMap("./textures/crosshair.png");
	float sVel = 0;
	float sAcc = 0;
	float xSpd = 0;
	float ySpd = 0;
	float sX = 60;
	float eX = 660;
	float eY = 300;
	float sY = 300;
	float bX = sX + 70;
	float bY = sY + 3;
	float sYD = sfw::getDeltaTime();
	float acc = 0;
	char c = '\0';
	float a = 0;
	float b = 800;
	float aa = a;
	float ab = b;
	float ac = 0;
	float ad = 1920;
	bool fire = false;
	sfw::setBackgroundColor(WHITE);
		
	while (sfw::stepContext())
	{

		sfw::drawTexture(r, a, 600, 800, 600, 0, false, 0, WHITE);
		sfw::drawTexture(r, b, 600, 800, 600, 0, false, 0, WHITE);
		sfw::drawTexture(asb, aa, 600, 2024, 600, 0, false, 0, 0x777700ff);
		sfw::drawTexture(asb, ab, 600, 2024, 600, 0, false, 0, 0x777700ff);
		sfw::drawTexture(neb, ac, 600, 1920, 1080, 0, false, 0, 0xffffff22);
		sfw::drawTexture(neb, ad, 600, 1920, 1080, 0, false, 0, 0xffffff22);
		acc += sfw::getDeltaTime();


		//xSpeed = ySpeed = 0;
		//if(keyPressed) xSpeed = 10;
		//if(keyPressed) ySpeed = 10;

		// pX += xSpeed * deltaTime;
		// pY += ySpeed * deltaTime;
		int temp = 0;
		if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
		{
			temp = temp + 1;
		}
		
		//sfw::drawString(d, "TIME 4 FUN", 400, 300, 120, 80, acc * 145, '\0', WHITE);
		sX += xSpd * sfw::getDeltaTime();
		sY += ySpd * sfw::getDeltaTime();
		sfw::drawTexture(enemy, eX--, 300, 128, 128, 0, true, acc * 15);
		sfw::drawTexture(d, sX, sY, 128, 128, 0, true, acc * 15);
	

		if (sfw::getKey(87) || sfw::getKey(83) || sfw::getKey(65) || sfw::getKey(68) || sfw::getKey(257))
		{

			if (sfw::getKey(87))//w
			{
				ySpd = 200;

			}
			if (sfw::getKey(83))//s
			{
				ySpd = -200;

			}
			if (sfw::getKey(65))//a
			{
				xSpd = -200;

			}
			if (sfw::getKey(68))//d
			{
				xSpd = 200;

			}
			if (sfw::getKey(257))
			{
				fire = true;
			}

		}
		else
		{
			xSpd = 0;
			ySpd = 0;
		}
			
	
			if (sX < 50 && xSpd < 0 || sX > 750 && xSpd > 0 || sY < 30 && ySpd < 0 || sY > 570 && ySpd > 0)
		{

			xSpd = 0;
			ySpd = 0;
		}

			if (fire == true)
			{
				bulletF(bullet, bX * acc, bY);

				if (bX > 660)
				{
					fire = false;
					float bX = sX + 70;
					float bY = sY + 3;
				}
			}
		/*else
			{
				sfw::drawTexture(d, sX, sY, 100, 64, 0, true, acc * 15);
			}*/
					/*if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
					{
						sfw::drawTexture(d, 60, 300, 100, 64, 0, true, 1);
					}
					else
					{
						sfw::drawTexture(d, 60, 300, 100, 64, 0, true, 0);
					}*/
			
			//sfw::drawString(d, "2", 30, 300, 100, 64);
			//sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
			//sfw::drawString(d, "3", 800-32, 300, 24, 24);
			//sfw::drawString(d, "9", 32, 300, 24, 24);

			//if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
				//sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2.5, sfw::getTextureHeight(u) / 2.5, 45, true, 0, 0x88ffffff);
			 //sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
			
	        a -= 1;
			b -= 1;
			if (a <= -800)
			{
				a = 800;
			}
			if (b <= -800)
			{
				b = 800;
			}
			aa -= 3;
			ab -= 3;
			if (aa <= -2024)
			{
				aa = 800;
			}
			if (ab <= -2024)
			{
				ab = 800;
			}
			ac -= 8;
			ad -= 8;
			if (ac <= -1920)
			{
				ac = 1920;
			}
			if (ad <= -1920)
			{
				ad = 1920;
			}
	}

	sfw::termContext();
}