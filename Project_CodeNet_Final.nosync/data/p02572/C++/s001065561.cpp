#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll s = 0;
	for (int i = 0; i < n; i++) {
		s = (s + a[i]) % MOD;
	}

	ll ans = (s * s) % MOD;

	for (int i = 0; i < n; i++) {
		ll p = a[i];
		p = (p * p) % MOD;
		ans = (ans + MOD - p) % MOD;
	}

	ll inv2 = MOD - MOD / 2;
	
	ans = (ans * inv2) % MOD;
	cout << ans << endl;

}