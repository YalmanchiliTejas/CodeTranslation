#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<string> S(N, "");
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}

	map<char, int> ch_count;

	for (char i = 'a'; i <= 'z'; i++)
	{
		int min_count = 51;
		for (int j = 0; j < N; j++)
		{
			int curr_count = 0;
			for (int k = 0; k < S[j].size(); k++)
			{
				if (S[j][k] == i) curr_count++;
			}

			min_count = min(min_count, curr_count);
		}

		ch_count[i] = min_count;
	}

	string result;
	for (auto e : ch_count)
	{
		for (int i = 0; i < e.second; i++)
		{
			result.push_back(e.first);
		}
	}

	cout << result;

	return 0;
}
