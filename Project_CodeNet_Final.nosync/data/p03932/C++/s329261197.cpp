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
const long long MOD = 1000000000 + 7;//1000000000 + 7 998244353 924844033 1000000000 + 9;
constexpr long long INF = 1LL << 60;//numeric_limits<LL>::max();
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
set<LL>st;
map<Pll, LL>ma;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
string str, ss;
bool f;
LL n, m, s, t, h, w, k, q, p, ans, sum, cnt, a[300][300], b[21], dp[400][200][200];
int main() {
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	dp[0][0][0] = a[0][0];
	rep(st, h + w-1) {
		rep(sx, h) {
			rep(tx, h) {
				LL sy = st - sx, ty = st - tx;
				if (dp[st + 1][sx][tx] < dp[st][sx][tx] + (sx == tx ? a[sx][st - sx + 1] : a[sx][st - sx + 1] + a[tx][st - tx + 1])) {
					dp[st + 1][sx][tx] = dp[st][sx][tx] + (sx == tx ? a[sx][st - sx + 1] : a[sx][st - sx + 1] + a[tx][st - tx + 1]);
				}
				if (sx + 1 < h) {
					if (dp[st + 1][sx + 1][tx] < dp[st][sx][tx] + (sx + 1 == tx ? a[sx + 1][st - sx] : a[sx + 1][st - sx] + a[tx][st - tx + 1])) {
						dp[st + 1][sx + 1][tx] = dp[st][sx][tx] + (sx + 1 == tx ? a[sx + 1][st - sx] : a[sx + 1][st - sx] + a[tx][st - tx + 1]);
					}
				}

				if (tx + 1 < h) {
					if (dp[st + 1][sx][tx + 1] < dp[st][sx][tx] + (sx == tx + 1 ? a[sx][st - sx + 1] : a[sx][st - sx + 1] + a[tx + 1][st - tx])) {
						dp[st + 1][sx][tx + 1] = dp[st][sx][tx] + (sx == tx + 1 ? a[sx][st - sx + 1] : a[sx][st - sx + 1] + a[tx + 1][st - tx]);
					}
				}

				if (tx + 1 < h&&sx + 1 < h) {
					if (dp[st + 1][sx + 1][tx + 1] < dp[st][sx][tx] + (sx + 1 == tx + 1 ? a[sx + 1][st - sx] : a[sx + 1][st - sx] + a[tx + 1][st - tx])) {
						dp[st + 1][sx + 1][tx + 1] = dp[st][sx][tx] + (sx + 1 == tx + 1 ? a[sx + 1][st - sx] : a[sx + 1][st - sx] + a[tx + 1][st - tx]);
					}
				}

			}
		}
	}
	cout << dp[h + w - 2][h - 1][h - 1] << endl;
	return 0;
}