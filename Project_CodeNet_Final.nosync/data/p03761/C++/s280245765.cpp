#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	string ans = "";
	cin >> N;

	vector<string> S(N);
	int A[27][50];

	for (int i = 0;i < 27;i++)
		for (int j = 0;j < 50;j++)
			A[i][j] = 0;

	for (int i = 0;i < N;i++)
	{
		cin >> S[i];

		for (int j = 0;j < S[i].size();j++)
		{
			int p = S[i][j] - 'a';
			A[p][i]++;
		}
	}

	for (int i = 0;i < 27;i++)
	{
		bool flag = true;
		int Min = 100;
		for (int j = 0;j < N;j++)
		{
			if (A[i][j] > 0)
			{
				Min = min(A[i][j], Min);
			}
			else
				flag = false;
		}


		if (flag)
		{
			for (int j = 0;j < Min;j++)
				ans.push_back((char)(i + 'a'));
		}
	}

	cout << ans << endl;

	return 0;
}
