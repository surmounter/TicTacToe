#include "TicTacToeController.h"
#include <iostream>
#include "TicTacToeModel.h"
#include "TicTacToeView.h"

TicTacToeController::TicTacToeController()
{
	_model = std::make_unique<TicTacToeModel>();
	_view = std::make_unique<TicTacToeView>(_model->GetBoardSlotCnt());
}

TicTacToeController::~TicTacToeController()
{
}

void TicTacToeController::OnStartGameLoop(sf::RenderWindow & window) const
{
	std::cout << "On Start Game Loop" << std::endl;		
	_view->UpdateBoard(_model->GetBoard(), window);
}

void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const Point & mouseClickPoint) const
{
	std::cout << "On Click MouseButton : " << mouseClickPoint.GetX() << "," << mouseClickPoint.GetY() << std::endl;
	_model->PutHorse(mouseClickPoint, window);
	_model->ShowResultOfTurn();
	_view->UpdateBoard(_model->GetBoard(), window);

	auto winner = _model->GetGameResult();
	if (winner != TicTacToeGameResult::NONE)
	{
		auto isRestart = _model->AskRestart(winner);
		if (isRestart)
		{
			_model->Initialize();
			_view->UpdateBoard(_model->GetBoard(), window);
		}
		else
		{
			//TODO : close window
		}
	}
		
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
