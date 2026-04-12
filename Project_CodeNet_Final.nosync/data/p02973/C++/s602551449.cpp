#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
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
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y))); }
double SQSUM(double x, double y) { return x * x + y * y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;


// 最長増加部分列(LIS: Longest Increasing Subsequence)
// 値が以上のときと、より大きいで、ちょっと違うので注意
int lis(const vector <int>& order)
{
	int max_len = 0;
	const int M = SZ(order);
	// O(nlogn) Mは文字数で、min_last_value[l]は 長さl+1のつくるときに、増加列の最後の数値の最小値
	vector <int> min_value(M, BIG);

	for (int i = 0; i < M; i++)
	{
		*upper_bound(min_value.begin(), min_value.end(), order[i]) = order[i]; // 以上
																			   //		*lower_bound(min_value.begin(),min_value.end(),order[i])=order[i]; // より大きい
	}

	max_len = lower_bound(min_value.begin(), min_value.end(), BIG) - min_value.begin();

	return max_len;
}


int main()
{
	int n;
	cin >> n;

	vector <int> a;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	reverse(a.begin(), a.end());

	ll ret = lis(a);

	cout << ret << endl;


	return 0;
}
