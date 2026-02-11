#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


void writeCommands()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "Hello world!" << std::endl;
	std::cout << "W/A/S/D - movement" << std::endl;
	std::cout << "H - help" << std::endl;
}



int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1200,800 }), "New entity");
	window.setFramerateLimit(60);

	sf::RectangleShape block = sf::RectangleShape({ 100,100 });
	block.setFillColor(sf::Color::Green);
	block.setPosition({ 200,300 });

	sf::RectangleShape block2 = sf::RectangleShape({ 100,100 });
	block2.setFillColor(sf::Color::Green);
	block2.setPosition({ 800,300 });
	
	sf::CircleShape player2;
	player2.setRadius(50);
	player2.setOutlineColor(sf::Color::Blue);
	player2.setOutlineThickness(5);
	player2.setPosition({ 520, 340 });

	


	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		sf::Vector2 prevPos = player2.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H))
		{
			writeCommands();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			std::cout << "W is pressed" << std::endl;
			player2.move({ 0.f,-10.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			std::cout << "S is pressed" << std::endl;
			player2.move({ 0.f,10.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			std::cout << "A is pressed" << std::endl;
			player2.move({ -10.f,0.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			std::cout << "D is pressed" << std::endl;
			player2.move({ 10.f,0.f });
		}

		if (player2.getGlobalBounds().findIntersection(block.getGlobalBounds())) {
			std::cout << "Collision detected!" << std::endl;
			player2.setPosition(prevPos);
			block.setFillColor(sf::Color::Red);
		}
		else
		{
			block.setFillColor(sf::Color::Green);
		}
		if (player2.getGlobalBounds().findIntersection(block2.getGlobalBounds())) {
			player2.setPosition(prevPos);
			std::cout << "Collision detected!" << std::endl;
			block2.setFillColor(sf::Color::Red);
		}
		else
		{
			block2.setFillColor(sf::Color::Green);
		}

		

		window.clear();

		window.draw(block);
		window.draw(block2);
		window.draw(player2);
		

		window.display();
	}


	std::cout << "Goodbye world!" << std::endl;
	
	return 0;
}

