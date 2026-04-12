
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

constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1 << 28;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n, m, k;
vector<bool> dark;
vector<int> cnv;
vector<ll> dp;
vector<vector<int>> g;

int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	scanf("%d %d %d", &n, &m, &k);
	dark = vector<bool>(n, false);
	cnv = vector<int>(n, -1);
	dp = vector<ll>((1 << m), -1);
	for (int i = 0; i < m; i++) {
		int d; scanf("%d", &d);
		dark[d - 1] = true;
		cnv[d - 1] = i;
	}
	g.resize(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int v; scanf("%d", &v);
			v--;
			if (dark[i]) g[cnv[i]].push_back(cnv[v]);
		}
	}
	queue<int> q;
	dp[(1 << m) - 1] = 0;
	q.push((1 << m) - 1);
	while (!q.empty()) {
		int S = q.front();
		q.pop();
		for (int i = 0; i < k; i++) {
			int nS = 0;
			for (int j = 0; j < m; j++) {
				if (S >> j & 1) {
					if(g[j][i] != -1) nS |= (1 << g[j][i]);
				}
			}
			if (dp[nS] == -1) {
				dp[nS] = dp[S] + 1;
				q.push(nS);
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
	/*
		おまじないを使ったらscanfとprintf関連注意！！！！！！！！！！！！
	*/
}

