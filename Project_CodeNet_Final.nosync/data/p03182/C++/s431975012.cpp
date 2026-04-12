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
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans, a[200020], b[220000],dp[220000];
string str, ss;
bool f[220000];
char c[4000][4000];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<Edge>>vec,rvec;
vector<edge>ed;
vector<LL>v;
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

template <typename T,T NV>
struct Starry_Sky {

	LL n=NV;
	vector<T> segMin, segAdd;
	Starry_Sky() {
		segMin.resize(n * 2 - 1, 0);
		segAdd.resize(n * 2 - 1, 0);
	}
	//区間[a, b)に値xを加算する.
	void add(int a, int b, T x, int k=0, int l=0, int r=NV)
	{
		if (r <= a || b <= l) return; //もし交差しない区間であれば終える.

		if (a <= l && r <= b) { //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
			segAdd[k] += x;  //区間[l, r)にkを加算する.
			return;
		}

		add(a, b, x, k * 2 + 1, l, (l + r) / 2); //子の区間に(必要があれば)xを加算する.
		add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃

												 //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である.一様に加算される値は更新しなくて良い.
		segMin[k] = max(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
	}

	T getMin(int a, int b, int k = 0, int l = 0, int r = NV)
	{
		if (r <= a || b <= l) return -INF/2;

		if (a <= l && r <= b) return (segMin[k] + segAdd[k]); //完全に内包されていれば,その区間の最小値を返す.

		T left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
		T right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める

		return (max(left, right) + segAdd[k]); //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である (大切なので2回書きました!!)

	}
};
Starry_Sky<LL,1<<20> seg;
struct query { LL l, r, a; };
vector<query>L[220000], R[220000];
int main() {
	cin >> n >> m;
	rep(i, m) {
		LL x, y, z;
		cin >> x >> y >> z;
		L[x].push_back(query{ x,y,z });
		R[y].push_back(query{ x,y,z });
	}
	for (int i = 1; i <= n; i++) {
		rep(j, L[i].size())
			seg.add(0, i, L[i][j].a);

		dp[i] = seg.getMin(0, i);
		ans = max(ans, dp[i]);
		seg.add(i, i + 1, dp[i]);

		rep(j, R[i].size())
			seg.add(0, R[i][j].l, -R[i][j].a);

	}
	cout << ans << endl;
	return 0;
}
