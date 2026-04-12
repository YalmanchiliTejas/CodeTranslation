#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define double long double
#define INF LLONG_MAX
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, m, k, kaijo[200010];
int mypow(int a, int b) {
	if (!b)return 1;
	if (b % 2)return mypow(a, b - 1) * a % moder;
	int c = mypow(a, b / 2);
	return c * c % moder;
}
int comb(int a, int b) {
	return kaijo[a] * mypow(kaijo[a - b], moder - 2) % moder * mypow(kaijo[b], moder - 2) % moder;
}
signed main() {
	cin >> n >> m >> k;
	kaijo[0] = 1;
	REP(i, 200000) {
		kaijo[i] = kaijo[i - 1] * i;
		kaijo[i] %= moder;
	}
	int ans = 0;
	REP(i, n - 1) {
		ans += i * (n - i) % moder * m % moder * m % moder;
		ans %= moder;
	}
	REP(i, m - 1) {
		ans += i * (m - i) % moder * n % moder * n % moder;
		ans %= moder;
	}
	cout << ans * comb(n * m - 2, k - 2) % moder << endl;
	return 0;
}