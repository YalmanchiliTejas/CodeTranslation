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

const double EPS = 1e-10;
typedef long long ll;
typedef pair<int, int> pint;

void operate(int* ori, int* next, const int* ope, int dir)
{
	for (int i = 0; i < 4; ++i)
		next[ope[(i+dir) % 4]] = ori[ope[i]];
}
int main()
{
	const int NS[] = { 0, 4, 5, 1 };
	const int EW[] = { 0, 2, 5, 3 };
	const int RL[] = { 1, 3, 4, 2 };
	const char* s = "NSEWRL";
	const int* op[] = { NS, NS, EW, EW, RL, RL };
	const int dir[] = { 1, 3, 1, 3, 1, 3 };
	int n;
	while (scanf("%d", &n), n)
	{
		int res = 1;
		int dice[] = { 1, 2, 3, 4, 5, 6 };
		while (n--)
		{
			char buf[16];
			scanf("%s", buf);

			int ori[6];
			memcpy(ori, dice, sizeof(ori));
			int t = strchr(s, buf[0]) - s;
			operate(ori, dice, op[t], dir[t]);
			res += dice[0];
		}
		printf("%d\n", res);
	}

	return 0;
}