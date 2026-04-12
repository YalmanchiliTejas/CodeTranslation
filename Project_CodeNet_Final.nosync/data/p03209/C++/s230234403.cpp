#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll func(int N, ll X, vector<ll>& num, vector<ll>& pat)
{
	if (X <= 0)
	{
		return 0;
	}
	if (X >= num[N])
	{
		return pat[N];
	}

	auto half = num[N] / 2 + 1;
	auto sum = 0ll;
	if (X < half)
	{
		sum += func(N - 1, X - 1, num, pat);
	}
	else
	{
		sum += func(N - 1, num[N - 1], num, pat);
		++sum;
		auto sub = num[N - 1] + 2;
		sum += func(N - 1, X - sub, num, pat);
	}

	return sum;
}

int main()
{
	int N;
	ll X;
	cin >> N >> X;

	vector<ll> num;
	vector<ll> pat;
	num.push_back(1);
	pat.push_back(1);
	for (auto i = 0; i < N; ++i)
	{
		num.push_back(num[i] * 2 + 3);
		pat.push_back(pat[i] * 2 + 1);
	}

	cout << func(N, X, num, pat) << endl;

	return 0;
}