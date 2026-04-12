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
#define sz(x) x.size()
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

bool G[21][21];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	memset(G, 0, sizeof(G));
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a][b] = G[b][a] = true;
	}
	int res = 0;
	vector<int>ord;
	rep(i, n)ord.push_back(i);
	do {
		if (ord[0] != 0)continue;
		bool ok = true;
		for (int i = 0; i + 1 < ord.size(); i++) {
			if (!G[ord[i]][ord[i + 1]])ok = false;
		}
		if (ok)res++;
	} while (next_permutation(ord.begin(), ord.end()));
	cout << res << endl;
	return 0;
}