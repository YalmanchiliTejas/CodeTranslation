
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

int N;
vector<LL>d;

template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int i, int j) {
		if (i == 0) {
			T S = 0;
			for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
			return S;
		}
		else return sum(0, j) - sum(0, i - 1);
	}
	void add(int k, T a) {
		for (; k < x.size(); k |= k + 1) x[k] += a;
	}
};

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		LL dd; cin >> dd;
		d.push_back(dd);
	}
	for (int loopcnt = 0; loopcnt < 2; ++loopcnt)
	{
		LL M = 1;
		while (M < 1e6)M *= 2;
		fenwick_tree<LL>bit(M);
		bit.add(0, 1);
		bit.add(1, -1);
		int isGood;
		for (int i = 0; i < N; ++i)
		{
			isGood = bit.sum(0, i);
			assert(isGood >= 0);
			if (isGood)
			{
				int next = d[i] / 10;
				bit.add(i + 1, 1);
				bit.add(i + next + 1, -1);
			}
		}
		if (isGood)
		{
		}
		else
		{
			cout << "no\n";
			return 0;
		}
		reverse(d.begin(), d.end());
	}
	cout << "yes\n";
	return 0;
}