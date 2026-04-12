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
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;// ;//1000000000 + 7 998244353 924844033 1000000000 + 9;
constexpr long long INF = numeric_limits<LL>::max();
constexpr long long DINF = 1000000000000;
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<double, double> Dll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
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
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<Edge>>g;
vector<edge>ed;
vector<Pll>pv;
map<LL, LL>ma;
set<LL>st;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
LL n, m, k, p, q, w, h, ans, cnt, a[310000], b[310000];
string str;
bool f;
//char c[1100][1100];
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
Combination comb(210000,MOD);
int main() {
	cin >> n >> m >> k;
	vector<vector<LL>>sum(n+1, vector<LL>(m+1));
	rep(i, n) {
		sum[i + 1][0] = i + 1;
		rep(j, m) {
			sum[i][j + 1] += j + i + 1 + sum[i][j];
			sum[i][j + 1] %= MOD;
		}
	}
	rep(i, n) {
		rep(j, m) {
			sum[i + 1][j] += sum[i][j];
			sum[i + 1][j] %= MOD;
		}
	}
	rep(i, n) {
		rep(j, m) {
			ans += (sum[i][j] + sum[i][m - j-1] + sum[n - i-1][j] + sum[n - i-1][m - j-1])%MOD+
				(MOD- (sum[0][j] + sum[0][m - j-1] + sum[i][0] + sum[n - i-1][0])%MOD);
			ans %= MOD;
		}
	}
	cout << (ans * comb.C(n*m - 2, k - 2) % MOD)*comb.inv(2)%MOD << endl;
	return 0;
}
