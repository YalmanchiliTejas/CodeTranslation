#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include<set>


#define rep(i,p,q) for(ll i = p;i < q;++i)
#define ll long long

using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll npk(ll n, ll k) {
	ll ret = 1;
	if (n < k || n < 0)return 0;
	rep(i, 0, k) {
		ret *= (n - i);
		ret %= MOD;
	}
	if (ret < 0) ret = 0;
	return ret;
}


//134 E
int main(void) {
	ll n;
	cin >> n;
	vector<ll> a = vector<ll>(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	multiset<ll> color;
	rep(i, 0, n) {
		auto itr = color.lower_bound(a[i]);
		if (itr == color.begin()) {
			color.insert(a[i]);
		}
		else {
			color.erase(--itr);
			color.insert(a[i]);
		}
	}
	cout << color.size() << endl;
}
