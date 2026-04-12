#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

unsigned long long calc(int L, unsigned long long X, vector<pair<unsigned long long, unsigned long long>>& num)
{
	if (X <= 0)
	{
		return 0;
	}
	if (L < 0)
	{
		return 0;
	}
	if (L == 0)
	{
		return 1;
	}

	auto& n = num[L];
	auto half = n.first / 2;
	auto sum = 0ull;

	if (X > half + 1)
	{
		sum += calc(L - 1, min(half - 1, X - half - 1), num);
		sum += num[L - 1].second;
		++sum;
	}
	else if (X == half + 1)
	{
		sum += num[L - 1].second;
		++sum;
	}
	else
	{
		sum += calc(L - 1, X - 1, num);
	}

	return sum;
}

int main()
{
	int N;
	unsigned long long X;
	cin >> N >> X;

	vector<pair<unsigned long long, unsigned long long>> num;
	num.push_back(make_pair(1ull, 1ull));
	for (auto i = 1; i <= N; ++i)
	{
		auto& prev = num[i - 1];
		num.push_back(make_pair(prev.first * 2 + 3, prev.second * 2 + 1));
	}

	cout << calc(N, X, num) << endl;

	return 0;
}
