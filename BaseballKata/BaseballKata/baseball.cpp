#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball 
{
public:
	static constexpr int MAX_DIGITS = 3;
	explicit Baseball(const string& question) : question{ question } {}

	GuessResult guess(const string& guessNumber) 
	{
		assertIllegalArgument(guessNumber);
		GuessResult result = updateResult(guessNumber);
		return result;
	}

private:
	string question;

	GuessResult updateResult(const string& guessNumber)
	{
		int strikes = getStrikes(guessNumber);
		int balls = getBalls(guessNumber);
		bool solved = IsSolved(strikes);
		return { solved, strikes, balls };
	}

	int getStrikes(const string& guessNumber)
	{
		int strikes = 0;
		for (int index = 0; index < MAX_DIGITS; index++)
		{
			if (guessNumber[index] == question[index]) strikes++;
		}
		return strikes;
	}

	int getBalls(const string& guessNumber)
	{
		int balls = 0;

		for (int questionIndex = 0; questionIndex < MAX_DIGITS; questionIndex++)
		{
			for (int guessIndex = 0; guessIndex < MAX_DIGITS; guessIndex++)
			{
				if (questionIndex == guessIndex) continue;
				if (guessNumber[questionIndex] == question[guessIndex]) balls++;
			}
		}
		
		return balls;
	}

	bool IsSolved(int strikes)
	{
		return strikes == MAX_DIGITS;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != MAX_DIGITS)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");

		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number.");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] || guessNumber[0] == guessNumber[2] || guessNumber[2] == guessNumber[1];
	}

};