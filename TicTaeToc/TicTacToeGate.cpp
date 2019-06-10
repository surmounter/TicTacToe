#include "TicTacToeGate.h"
#include "TicTacToeController.h"

TicTacToeGate::TicTacToeGate(const WindowSize windowSize)
{
	_window.create(sf::VideoMode(windowSize.first, windowSize.second), _gameTitle, sf::Style::Close);
	_controller = std::make_unique<TicTacToeController>();
}

TicTacToeGate::~TicTacToeGate()
{
}

void TicTacToeGate::UpdateGameLoop()
{
	_controller->OnStartGameLoop(_window);
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				_controller->OnClickMouseButton(_window, std::make_pair(event.mouseButton.x, event.mouseButton.y));
				break;
			case sf::Event::Closed:
				_controller->OnCloseWindow();
				_window.close();
				break;
			default:
				break;
			}				
		}
	}
}

