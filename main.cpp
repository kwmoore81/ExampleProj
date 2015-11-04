
#include "sfwdraw.h"




void main()
{
	sfw::initContext(800,600,"NSFW Draw");
	
	unsigned d = sfw::loadTextureMap("./textures/purpleship2.png", 2, 1);
	//unsigned d = sfw::loadTextureMap("./textures/fontmap.png",16,16);
	//unsigned r = sfw::loadTextureMap("./textures/background.jpg");
	unsigned r = sfw::loadTextureMap("./textures/space.jpg");
	unsigned asb = sfw::loadTextureMap("./textures/asteroidbelt.png");
	unsigned neb = sfw::loadTextureMap("./textures/nebula.png");
	unsigned u = sfw::loadTextureMap("./textures/crosshair.png");

	float acc = 0;
	char c = '\0';
	float a = 0;
	float b = 800;
	float aa = a;
	float ab = b;
	float ac = 0;
	float ad = 1920;

	sfw::setBackgroundColor(WHITE);

	while (sfw::stepContext())
	{
		
			sfw::drawTexture(r, a , 600, 800, 600, 0, false, 0, WHITE);
			sfw::drawTexture(r, b , 600, 800, 600, 0, false, 0, WHITE);
			sfw::drawTexture(asb, aa, 600, 2024, 600, 0, false, 0, BLACK);
			sfw::drawTexture(asb, ab, 600, 2024, 600, 0, false, 0, BLACK);
			sfw::drawTexture(neb, ac, 600, 1920, 1080, 0, false, 0, 0xffffff22);
			sfw::drawTexture(neb, ad, 600, 1920, 1080, 0, false, 0, 0xffffff22);
			acc += sfw::getDeltaTime();
			//sfw::drawString(d, "TIME 4 FUN", 400, 300, 120, 80, acc * 145, '\0', WHITE);
			

					
				
					if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
					{
						sfw::drawTexture(d, 60, 300, 100, 64, 0, true, 1);
					}
					else
					{
						sfw::drawTexture(d, 60, 300, 100, 64, 0, true, 0);
					}
			
			//sfw::drawString(d, "2", 30, 300, 100, 64);
			//sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
			//sfw::drawString(d, "3", 800-32, 300, 24, 24);
			//sfw::drawString(d, "9", 32, 300, 24, 24);

			if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
				sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2.5, sfw::getTextureHeight(u) / 2.5, 45, true, 0, 0x88ffffff);
			else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
			
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