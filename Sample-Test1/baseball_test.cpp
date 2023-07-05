#include "pch.h"
#include "../baseball/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}