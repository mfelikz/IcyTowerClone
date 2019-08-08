#include <Layer.h>

Layer::Layer()
{
	view.reset(sf::FloatRect(0, 0, 640, 480));
	camY = 0;
	speedDelta = 1;
	step = const_cam_start_step;
}

Layer::Layer(float speedDelta)
{
	view.reset(sf::FloatRect(0, 0, 640, 480));
	camY = 0;
	step = const_cam_start_step - const_cam_start_step / speedDelta;
	this->speedDelta = speedDelta;
}

void Layer::move()
{
	float camSpeed = Camera::getCamSpeed();
	view.reset(sf::FloatRect(0, camY, 640, 480));
	camY -= const_cam_speed_delta * camSpeed * speedDelta;
	step -= camSpeed;
	if (step <= 0) 
	{
		camY = 0;
		if (speedDelta != 1) {
			step = const_cam_start_step - const_cam_start_step / speedDelta;
		}
		else step = const_cam_start_step;
	}
}

void Layer::render(sf::RenderWindow& window, sf::Drawable& sprite)
{
	window.setView(view);
	window.draw(sprite);
}