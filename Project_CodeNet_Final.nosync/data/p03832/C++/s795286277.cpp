#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm> 
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e3 + 15;
int n, a, b, c, d, ans, dp[N][N], C[N][N], dp2[N][N], rev[N], fact[N];

// dp2[i people][j groups]


inline void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
}

inline int mt(int a, int b) {
	return ((ll)a * b) % mod;
}

inline void precalc() {
	C[0][0] = 1;
	for(int i = 1; i < N; ++i)
		for(int j = 0; j <= i; ++j)
			add(C[i][j], C[i-1][j] + (j ? C[i-1][j-1] : 0));
	rev[1] = 1;
	for(int i = 2; i < N; ++i)
		add(rev[i], -mt(mod / i, rev[mod % i]));
	for(int i = 1; i < N; ++i) {
		dp2[i][1] = 1;
		for(int j = 2; j * i < N; ++j)
			dp2[i][j] = mt(mt(dp2[i][j-1], C[i * j][i]), rev[j]);
	}
}

main() {
	precalc();
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	// dp2[i size][j groups] - number of ways to distribute i people in j groups
	// dp[i people][size >= j]
	dp[0][b+1] = 1;
	for(int j = b; j >= a; --j)
		for(int i = n; i >= 0; --i) {
			dp[i][j] = dp[i][j+1];
			for(int l = c; l <= d && j * l <= i; ++l)
				add(dp[i][j], mt(dp2[j][l], mt(C[i][j * l], dp[i - j * l][j+1])));
		}
	printf("%d\n", dp[n][a]);
    return 0;
}