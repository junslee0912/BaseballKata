#include "gmock/gmock.h"
#include "baseball.cpp"
#include "string"

class BaseballFixture : public testing::Test 
{
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber)
	{
		try 
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) 
		{
			//PASS
		}
	}

	void CompareResult(string guessNumber, int expectedStrikes, int expectedBalls)
	{
		GuessResult result = game.guess(guessNumber);
		EXPECT_EQ((expectedStrikes == Baseball::MAX_DIGITS), result.solved);
		EXPECT_EQ(expectedStrikes, result.strikes);
		EXPECT_EQ(expectedBalls, result.balls);
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
	string guessNumber = "123";
	int expectedStrikes = 3;
	int expectedBalls = 0;
	CompareResult(guessNumber, expectedStrikes, expectedBalls);
}

TEST_F(BaseballFixture, ReturnSolvedResultWith2S0B)
{
	string guessNumber = "127";
	int expectedStrikes = 2;
	int expectedBalls = 0;
	CompareResult(guessNumber, expectedStrikes, expectedBalls);
}

TEST_F(BaseballFixture, ReturnSolvedResultWith1S2B)
{
	string guessNumber = "132";
	int expectedStrikes = 1;
	int expectedBalls = 2;
	CompareResult(guessNumber, expectedStrikes, expectedBalls);
}