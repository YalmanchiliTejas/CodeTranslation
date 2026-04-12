// スタックサイズ: 100MB

#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <random>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define fst first
#define snd second
ll pw(ll x, ll y) { ll r = 1;  rep(i, y) { r *= x; }; return r; }




int main() {
	fastio;

	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	return 0;
}