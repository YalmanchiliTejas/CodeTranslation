# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>

//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourd; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)

LL h, w, n, m, k, t, s, p,q, last, cnt, sum, ans, dp[2000][2000], a[20000], b[20000];
string str, ss;
bool f[1100][1100];
char c;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
vector<Edge>vec;
vector<LL>v;
map<string, vector<LL>>ma;
multiset<LL>st[3];
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Combination {
	int mod;
	vector< int64_t > mfact, rfact;

	Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod) {
		mfact[0] = 1;
		for (int i = 1; i < mfact.size(); i++) {
			mfact[i] = mfact[i - 1] * i % mod;
		}
		rfact[sz] = inv(mfact[sz]);
		for (int i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % mod;
		}
	}

	int64_t fact(int k) const {
		return (mfact[k]);
	}

	int64_t pow(int64_t x, int64_t n) const {
		int64_t ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= mod;
			(x *= x) %= mod;
			n >>= 1;
		}
		return (ret);
	}

	int64_t inv(int64_t x) const {
		return (pow(x, mod - 2));
	}

	int64_t P(int n, int r) const {
		if (r < 0 || n < r) return (0);
		return (mfact[n] * rfact[n - r] % mod);
	}

	int64_t C(int p, int q) const {
		if (q < 0 || p < q) return (0);
		return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
	}

	int64_t H(int n, int r) const {
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};
Combination comb(100000, MOD);
LL partf(LL n,LL m) {
	if (dp[n][m] != -1)return dp[n][m];
	if (n == 0)return 1;
	if (n < m)return 0;
	if (m > q)return 0;
	LL ret = 0, cnt = 1;
	ret += partf(n, m + 1);
	for (int i = 1; i < h; i++) {
		if (n - m * i >=m) {
			cnt = (cnt*comb.C(n - m * (i-1), m)) % MOD;
		}
		else return dp[n][m] = 0;
	}
	for (int i = h; i <= w; i++) {
		cnt = (cnt*comb.C(n - m * (i-1), m)) % MOD;
		if (n - m * i >= 0) {
			ret += (((partf(n - i * m, m + 1)*cnt) % MOD)* comb.rfact[i]) % MOD;
			ret %= MOD;
		}
		else break;
	}
	return dp[n][m] = ret;
}
int main() {
	cin >> s >> p >> q >> h >> w;
	rep(i, 2000)rep(j, 2000)dp[i][j] = -1;
	cout << partf(s, p) << endl;
	return 0;
}
