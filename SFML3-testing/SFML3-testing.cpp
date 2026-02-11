#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1200,800 }), "New entity");
	window.setFramerateLimit(60);

	sf::RectangleShape player(sf::Vector2f({50, 50}));
	player.setOutlineColor(sf::Color::White);
	player.setPosition({ 10, 20 });

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player2.move({ 0.f,-10.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player2.move({ 0.f,10.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player2.move({ -10.f,0.f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player2.move({ 10.f,0.f });
		}

		window.clear();


		window.draw(player);
		window.draw(player2);
		

		window.display();
	}
	return 0;
}