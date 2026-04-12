#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const char R[11] = { 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'u', 'y' };

	string S;

	bool right[2];

	int Answer;

	vector<int> Ans;

	while (true)
	{
		Answer = 0;

		cin >> S;

		if (S == "#")
		{
			break;
		}

		for (int i = 0; i < S.size(); i++)
		{
			right[0] = right[1];

			right[1] = false;

			for (int j = 0; j < 11; j++)
			{
				if (S[i] == R[j])
				{
					right[1] = true;
				}
			}

			if (right[0] != right[1] && i != 0)
			{
				Answer++;
			}
		}

		Ans.push_back(Answer);
	}

	for (int i = 0; i < Ans.size(); i++)
	{
		cout << Ans[i] << endl;
	}

	return 0;
}