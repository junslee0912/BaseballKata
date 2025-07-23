#include "gmock/gmock.h"
#include "baseball.cpp"
#include "string"

TEST(BaseballGame, TC1)
{
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}