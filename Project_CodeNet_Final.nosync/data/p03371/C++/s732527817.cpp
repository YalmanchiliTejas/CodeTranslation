// スタックサイズ: 100MB

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
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define fst first
#define snd second
ll pw(ll x, ll y) { ll r = 1;  rep(i, y) { r *= x; }; return r; }


int main() {
	
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll tmp = min(x, y);
	ll ans = min(a + b, 2 * c) * tmp;
	tmp = max(x, y) - min(x, y);
	if (x > y) ans += min(a, 2 * c) * tmp;
	else ans += min(b, 2 * c) * tmp;
	cout << ans << endl;
}