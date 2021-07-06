#include "Player.h"
//Private functions

void Player::initVariables()
{
    this->movementSpeed = 10.f;
}

void Player::initTexture()
{
    if(!this->playerTexture.loadFromFile("Textures/nave.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE:: Failed to load texture!" << '\n' ;
    }
}

void Player::initShape()
{
    this->shape.setTexture(&this->playerTexture);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setPosition(375.f, 500.f);
}

//Constructor
Player::Player(float x, float y)
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}

//Destructor
Player::~Player()
{

}

//Funciones publicas
void Player::updateInput()
{
    //Entrada del teclado
    //Hacia la izquierda
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed, 0.f);
    }
    //Hacia la derecha
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.f);  
    }
    //Hacia arriba
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->movementSpeed);  
    }
    //Hacia abajo
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movementSpeed);  
    }
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget * target)
{
    //Limite izquierdo

    if (this->shape.getGlobalBounds().left <= 0.f)
    {
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    }
    //Limite derecho
    else if(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
    {
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
    }
    //Limite superior
    if (this->shape.getGlobalBounds().top <= 0.f)
    {
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
    }
    //Limite inferior
    else if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
    {
        this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
    }

}
void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}
void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
