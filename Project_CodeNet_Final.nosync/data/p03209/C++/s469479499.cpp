#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

vector<ll> pate(50 + 1);
vector<ll> all(50 + 1);

ll dfs(int _n, ll _x) {// _nレベル、下から_x枚
	if (_n == 0) return _x ? 1 : 0;
	if (_x == 1) return 0;
	else if (_x <= 1 + all[_n - 1]) return dfs(_n - 1, _x - 1);
	else if (_x == 2 + all[_n - 1]) return pate[_n - 1] + 1;
	else if (_x <= 2 + all[_n - 1] * 2) return pate[_n - 1] + 1 + dfs(_n - 1, _x - 2 - all[_n - 1]);
	else if (_x == 3 + all[_n - 1] * 2) return 1 + pate[_n - 1] * 2;
	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	ll x;
	cin >> x;

	// パティの枚数
	// 下から食べる
	pate[0] = 1;
	all[0] = 1;
	rep(i, n){
		pate[i + 1] = 1 + 2 * pate[i];
		all[i + 1] = 3 + 2 * all[i];
	}

	ll ans = dfs(n, x);
	cout << ans << endl;;

	return 0;
}