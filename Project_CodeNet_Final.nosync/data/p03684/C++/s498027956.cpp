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
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = std::numeric_limits<LL>::max();
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
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, q, last, cnt, sum, ans, dp[3000][3000];
Ppll a[200000];
string str;
bool f;
double Ans;
char c;
int di[4][2] = { { 0,1 },{ 1,0 },{ -1,0 } ,{ 0,-1 } };
struct Edge { LL from, to, cost; };
vector<Edge>vec[1000000],edge;
vector<Pll>v;
map<string, LL>ma;
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
int  par[1000000];
int find(int x) { if (par[x] == x)return x; par[x] = find(par[x]); return par[x]; }
void unite(int x, int y) { x = find(x); y = find(y); if (x == y)return; par[x] = y; }
bool same(int x, int y) { return find(x) == find(y); }
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i].fir >> a[i].sec.fir;
		a[i].sec.sec = i;
	}
	for (int i = 0; i<n+100; i++)par[i] = i;  // このように初期化
	sort(a, a + n);
	rep(i, n) {
		edge.push_back(Edge{ a[i].sec.sec,a[i + 1].sec.sec,abs(a[i].fir - a[i+1].fir) });
	}
	sort(a, a + n, [](Ppll x, Ppll y) {return x.sec.fir < y.sec.fir; });
	rep(i, n) {
		edge.push_back(Edge{ a[i].sec.sec,a[i + 1].sec.sec,abs(a[i].sec.fir - a[i+1].sec.fir) });
	}
	sort(edge.begin(), edge.end(), [](Edge x, Edge y) {return x.cost < y.cost; });
	rep(i,edge.size()) {
		if (!same(edge[i].to, edge[i].from)) {
			unite(edge[i].to, edge[i].from);
			ans += edge[i].cost;
		}
	}
	cout << ans << endl;
	return 0;
}