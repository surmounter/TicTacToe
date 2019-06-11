#include "TicTacToeBoard.h"
#include <string.h>
#include <iostream>
#include <cassert>

TicTacToeBoard::TicTacToeBoard()
{
	ClearBoard();
}

TicTacToeBoard::~TicTacToeBoard()
{
}

const bool TicTacToeBoard::MarkBoard(const HorseType::value horseType, const BoardSlot & boardSlot)
{
	if (IsEmpty(boardSlot) == false || IsOffBoard(boardSlot))
		return false;
	_board[boardSlot.y][boardSlot.x] = horseType;
	return true;
}

const BoardSlot TicTacToeBoard::ConvertMouseCoordToBoardCoord(const WindowSize & windowSize, const Point & mouseCoord) const
{
	assert(rowCnt > 0 && colCnt > 0, "Error will occur because divide by zero");
	BoardSlot boardSlot;
	boardSlot.x = mouseCoord.GetX() / (windowSize.width / rowCnt);
	boardSlot.y = mouseCoord.GetY() / (windowSize.height / colCnt);
	if (boardSlot.x >= rowCnt) boardSlot.x = rowCnt - 1;
	if (boardSlot.y >= colCnt) boardSlot.y = colCnt - 1;
	return boardSlot;
}

void TicTacToeBoard::ShowBoard() const
{
	for (int y = 0; y < rowCnt; ++y)
	{
		for (int x = 0; x < colCnt; ++x)
			std::cout << _board[y][x] << " ";
		std::cout << std::endl;
	}
}

