#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1 << 28;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


bool check(int x, vector<int>& a) {
	int n = a.size();
	int i = 0;
	for (; i < n; i++) {
		if (x % a[i] == 0) {
			return i % 2 == 0;
		}
	}
	return (n % 2 == 0);

}
void solve() {
	int n, l, r; scanf("%d %d %d", &n, &l, &r); if (n == 0 and l == 0 and r == 0) exit(0);
	vector<int> a(n); for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int res = 0;
	for (int i = l; i <= r; i++) res += check(i, a);
	printf("%d\n", res);
}

int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/

	int kkt = 89;
	while (kkt) {
		solve();
	}
	return 0;
}
