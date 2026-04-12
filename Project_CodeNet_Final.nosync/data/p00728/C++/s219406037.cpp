#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>

#define REP(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define ALLOF(c) c.begin(), c.end()
#define EPS 1e-9
using namespace std;

template <class T>
static T read()
{
	T t;
	cin >> t;
	return t;
}

template <class T>
static vector<T> read_n(int n)
{
	vector<T> v;
	REP(i,n) { v.push_back(read<T>()); }
	return v;
}

template <class T>
static void write(const T &t)
{
	cout << t << endl;
}

/// template end ///

int main()
{
	while (true)
	{
		int n = read<int>();
		if (!n) { break; }
		vector<int> v = read_n<int>(n);
		sort(ALLOF(v));
		int ret = accumulate(v.begin() + 1, v.end() - 1, 0) / (n - 2);
		write(ret);
	}
	return 0;
}