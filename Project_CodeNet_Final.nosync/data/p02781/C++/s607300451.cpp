#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

using namespace std;

int dp[100][4][2];

string N;
int K;

int process(int idx, int count, int limit)
{
	if (idx == N.size())
	{
		if (count == K) return 1;
		else return 0;
	}
	else if (count > K) return 0;
	
	int& ret = dp[idx][count][limit];
	if (ret != -1) return ret;
	ret = 0;

	int digit_max = 9;
	if (limit == 1)
	{
		digit_max = N[idx] - '0';
	}


	for (int i = 0; i <= digit_max; i++)
	{
		int next_count = count;
		if (i != 0)
		{
			next_count++;
		}

		int next_limit = 0;
		if (i == digit_max)
		{
			next_limit = 1;
		}

		ret += process(idx + 1, next_count, limit && next_limit);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill_n(&dp[0][0][0], sizeof(dp) / sizeof(int), -1);

	cin >> N;
	cin >> K;

	cout << process(0, 0, 1);

	return 0;
}