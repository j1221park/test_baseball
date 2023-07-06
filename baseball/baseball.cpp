#include <stdexcept>
using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		bool solved = false;
		int strikeCount = getStikeCount(guessNumber);
		int ballCount = getBallCount(guessNumber);
		return { solved, strikeCount, ballCount };
	}
private:
	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Mus be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const string& guessNumber) {
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
	int getStikeCount(const string& guessNumber) {
		int result = 0;
		for (int i = 0; i < guessNumber.size(); i++) {
			if (guessNumber[i] != question[i]) continue;
			result++;
		}
		return result;
	}
	int getBallCount(const string& guessNumber) {
		int cnt = 0;
		for (int i = 0; i < guessNumber.size(); i++) {
			for (int x = 0; x < question.size(); x++) {
				if (i == x) continue;
				if (guessNumber[i] != question[x]) continue;
				cnt++;
				break;
			}
		}
		return cnt;
	}
	string question;
};