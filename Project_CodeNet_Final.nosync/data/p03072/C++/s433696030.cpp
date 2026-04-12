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

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define all(v) (v).begin(), (v).end()
ll pw(ll x, ll y) { ll r = 1;  rep(i, y) { r *= x; }; return r; }


int main() {
	
	ll N;
	cin >> N;
	vll H(N), I(N);
	rep(i, N) {
		cin >> H[i];
		if (i == 0) I[0] = H[0];
		else I[i] = max(I[i - 1], H[i]);
	}

	ll ans = 0;
	rep(i, N) if (H[i] >= I[i]) ++ans;
	cout << ans << endl;
}