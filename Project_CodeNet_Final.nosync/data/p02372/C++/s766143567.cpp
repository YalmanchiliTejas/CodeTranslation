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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
const long long mod = 1000000007LL;
//const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n;
vector<vector<pair<int, int>>> g;
vector<int> dp;
vector<int> res;
int dfs1(int cur, int pre) {
	int res = 0;
	for (auto next : g[cur]) {
		if (next.first == pre) continue;
		chmax(res, dfs1(next.first, cur) + next.second);
	}
	return dp[cur] = res;
}

void dfs2(int cur, int pre) {
	res[cur] = dp[cur];
	ll sz = g[cur].size();
	vector<int> left(sz + 1, 0);
	vector<int> right(sz + 1, 0);
	for (int i = 0; i < sz; i++) left[i + 1] = max(left[i], dp[g[cur][i].first] + g[cur][i].second);
	for (int i = 0; i < sz; i++) right[i + 1] = max(right[i], dp[g[cur][sz - i - 1].first] + g[cur][sz - i - 1].second);
	for (int i = 0; i < sz; i++) {
		int next = g[cur][i].first;
		if (next == pre) continue;
		int tmp1 = dp[cur];
		int tmp2 = dp[next];
		dp[cur] = max(left[i], right[sz - i - 1]);
		dp[next] = max(dp[next], dp[cur] + g[cur][i].second);
		dfs2(next, cur);
		dp[cur] = tmp1;
		dp[next] = tmp2;
	}
}
int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	scanf("%d", &n);
	g.resize(n);
	dp = vector<int>(n);
	res = vector<int>(n);
	for (ll i = 0; i < n - 1; i++) {
		int s, t, w; scanf("%d %d %d", &s, &t, &w);
		g[s].emplace_back(t, w);
		g[t].emplace_back(s, w);
	}
	dfs1(0, -1);
	dfs2(0, -1);
	for (int i = 0; i < n; i++)  printf("%d\n", res[i]);
	return 0;
}

