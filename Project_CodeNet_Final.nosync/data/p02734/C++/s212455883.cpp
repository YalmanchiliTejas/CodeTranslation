#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef long long ll;

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

/////////////         modの計算

#define MOD_IS_PRIME
const ll mod = 998244353LL;

inline ll mod_adjust(ll a) {
	if (a >= mod) {
		return a % mod;
	}
	if (a < 0) {
		a *= -1;
		a--;
		if (a >= mod) { a %= mod; }
		a++;
		return mod - a;
	}
	return a;
}
inline ll mod_add(ll a, ll b) {
	return mod_adjust(a % mod + b % mod);
}
inline ll mod_sub(ll a, ll b) {
	return mod_adjust(a % mod - b % mod);
}
inline ll mod_multi(ll a, ll b) {
	return mod_adjust(mod_adjust(a) * mod_adjust(b));
}

int main() {
	int N, S; cin >> N >> S;
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> v(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(S + 1);
		for (int j = 0; j <= S; j++) {
			v[i][j] = 0;
		}
	}

	ll ans = 0;
	if (a[0] <= S) {
		v[0][a[0]] = 1;
	}
	for (int i = 1; i < N; i++) {
		if (a[i] == S) {
			ans = mod_add(ans, mod_multi(i + 1, N - i));
		}
		else if (a[i] < S) {
			ans = mod_add(ans, mod_multi(v[i - 1][S - a[i]], N - i));
		}
		for (int j = 1; j <= S; j++) {
			v[i][j] = v[i - 1][j];
		}
		for (int j = a[i] + 1; j <= S; j++) {
			v[i][j] = mod_add(v[i][j], v[i - 1][j - a[i]]);
		}
		if (a[i] <= S) {
			v[i][a[i]] = mod_add(v[i][a[i]], i + 1);
		}
	}

	cout << ans << endl;

	return 0;
}
