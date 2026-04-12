#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;

struct St
{
	int small;
	int big;
	bool operator < (const St &st) const
	{
		if (st.small == small)
		{
			return st.big > big;
		}
		return st.small > small;
	}
};


int N;
St st[200000];

int func1()
{
	int max = LLONG_MIN;
	int min_big = LLONG_MAX;
	for (int i = 0; i < N; i++)
	{
		max = MAX(max, st[i].big);
		min_big = MIN(min_big, st[i].big);
	}
	int min = st[0].small;

	int const_min_b = LLONG_MAX;
	int const_max_b = LLONG_MIN;
	for (int i = 0; i < N; i++)
	{
		if (st[i].small == min)
		{
			const_min_b = MIN(const_min_b, st[i].big);
			const_max_b = MAX(const_max_b, st[i].big);
		}
		if (st[i].big == max)
		{
			const_min_b = MIN(const_min_b, st[i].small);
			const_max_b = MAX(const_max_b, st[i].small);
		}
	}
	if (max == const_max_b || min == const_min_b) return LLONG_MAX;

	int min_b = LLONG_MAX;
	int max_b = LLONG_MIN;
	for (int i = 0; i < N; i++)
	{
		if (st[i].small != min)
		{
			min_b = MIN(min_b, st[i].small);
			max_b = MAX(max_b, st[i].small);
		}
	}

	int min_val = (max - min) * (MAX(max_b, const_max_b) - MIN(min_b, const_min_b));
	for (int i = 0; i < N; i++)
	{
		if (st[i].small == min || st[i].big == max) continue;

		min_b = (i < N - 1) ? st[i + 1].small : min_big;
		max_b = MAX(max_b, st[i].big);
		const_min_b = MIN(const_min_b, st[i].big);

		min_val = MIN(min_val, (max - min) * (MAX(max_b, const_max_b) - MIN(min_b, const_min_b)));
	}

	return min_val;
}

int func2()
{
	int min = st[0].small;
	int max = LLONG_MIN;
	int max_i;
	for (int i = 0; i < N; i++)
	{
		if (max < st[i].big)
		{
			max = st[i].big;
			max_i = i;
		}
	}
	int min_r = st[0].big;
	int max_b = st[max_i].small;
	for (int i = 1; i < N; i++)
	{
		if (i == max_i) continue;
		min_r = MIN(st[i].big, min_r);
		max_b = MAX(st[i].small, max_b);
	}
	return (max - min_r) * (max_b - min);
}

signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		int max = MAX(x, y);
		int min = MIN(x, y);
		st[i].small = min;
		st[i].big = max;
	}
	ARY_SORT(st, N);

	if (N == 1)
	{
		return 0;
	}

	int val = MIN(func1(), func2());

	cout << val << endl;
}