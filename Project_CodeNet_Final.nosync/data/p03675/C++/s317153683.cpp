#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}


int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	if (n % 2 == 1)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i % 2 == 1)
				continue;
			cout << x[i] << " ";
		}

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				continue;
			cout << x[i] << " ";
		}
	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i % 2 == 0)
				continue;
			cout << x[i] << " ";
		}

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 1)
				continue;
			cout << x[i] << " ";
		}
	}


	return 0;
}