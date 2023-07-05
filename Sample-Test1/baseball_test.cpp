#include "pch.h"
#include "../baseball/baseball.cpp"

class BaseballFixture:public testing::Test
{
public:
	Baseball game;
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
}