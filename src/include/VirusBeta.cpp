#include "VirusBeta.h"

void VirusBeta::initVariables()
{
    this->movementSpeed = 2.f;
    this->health = 100;
    this->points = 5;
}
void VirusBeta::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUS::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusBeta::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(40.f, 40.f));
    this->shape.setPosition(0, 0);
}

VirusBeta::VirusBeta()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
int VirusBeta::getPoints() const
{
    return this->points;
}
float VirusBeta::getMovementS()
{
    return this->movementSpeed;
}