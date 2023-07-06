#include "pch.h"
#include "../baseball/baseball.cpp"

class BaseballFixture:public testing::Test
{
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber)
	{
		// game.guess() 수행 후, Exception이 발생해야 PASS
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnFailedResultIf2Strikes0Balls)
{
	GuessResult result = game.guess("129");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}