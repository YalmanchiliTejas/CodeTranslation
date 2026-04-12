#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype

template <class T>
int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define popcount __builtin_popcount

template <class T> void get_max(T& a, const T b) { a = max(a, b); }
template <class T> void get_min(T& a, const T b) { a = min(a, b); }

const double EPS = 1e-10;
typedef long long ll;
typedef pair<int, int> pint;


int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int res = 0;
		stack<int> pos[2];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < 2; ++j)
				if (pos[j].empty())
					pos[j].push(0);

			int c;
			scanf("%d", &c);

			if (!c)
				++res;

			if (i & 1)
			{
				if (pos[c].top() == i - 1)
					pos[c].top() = i;
				else
					pos[c].push(i);
			}
			else
			{
				if (pos[c].top() == i - 1)
					pos[c].top() = i;
				else
				{
					int replaced = i - pos[c].top() - 1;
					pos[0].pop();
					pos[1].pop();
					pos[c].push(i);
					res += (c ? -1 : 1) * replaced;
				}
			}
		}
		printf("%d\n", res);
	}
}