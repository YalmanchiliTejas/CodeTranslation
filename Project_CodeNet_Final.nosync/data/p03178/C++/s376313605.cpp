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
using LL =long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7; //924844033 1000000000 + 9;
constexpr long long INF = numeric_limits<LL>::max();
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
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans,dp[11000][3][110], a[200000], b[200000];
string str, ss;
bool f;
char c[800][800];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<Edge>vec[20000];
vector<edge>ed;
vector<LL>v;
map<string,LL>ma;
set<LL>st;
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

int main() {
	cin >> str;
	cin >> n;
	dp[0][1][0] = 1;
	rep(i, str.size()) {
		rep(j, 2) {
			rep(l, n) {
				int lim = (j == 0 ? 9 : str[i] - '0');
				rep(k, lim+1) {
					bool flag = ((j == 1 && str[i] - '0' == k) ? 1 : 0);
					dp[i + 1][flag][(l + k) % n] += dp[i][j][l];
					dp[i + 1][flag][(l + k) % n] %= MOD;
				}
			}

		}
	}
	
	cout << (dp[str.size()][0][0]+ dp[str.size()][1][0]-1+MOD)%MOD << endl;
	return 0;
}
