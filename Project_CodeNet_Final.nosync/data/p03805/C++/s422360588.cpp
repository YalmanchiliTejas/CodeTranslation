#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
// *テンプレート*
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<int, int>
// aよりbの方が小さかったら、aの値をbの値に置き換える。(swapではない！)
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
// aよりbの方が大きかったら、aの値をbの値に置き換える。
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
//最大公約数
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
//最小公倍数
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
// 素数かどうか判定
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
// *テンプレートここまで*

// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]) {
	bool all_visited = true;
	rep(i, n) {
		if (!visited[i])all_visited = false;
	}
	if (all_visited)return 1;
	int ret = 0;
	rep(i, n) {
		if (!graph[v][i])continue;
		if (visited[i])continue;
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	bool visited[nmax]; rep(i, n)visited[i] = false;
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}