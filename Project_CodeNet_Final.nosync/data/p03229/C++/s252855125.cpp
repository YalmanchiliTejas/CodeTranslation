#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 201010;

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
char notes[110][10];
ll treasure[3030][3030];
ll dp[3030][3030][4];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n), num;
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll target = a[(n - 1) / 2];
	num.push_back(target);
	a.erase(a.begin() + (n - 1) / 2);
	ll i = 0;
	while (1) {
		num.push_back(a[n - 2 - i]);
		if (num.size() == n)break;
		num.push_back(a[i]);
		if (num.size() == n)break;
		i++;
	}
	if (n % 2) {
		vector<ll>num2(1);
		num2[0] = target;
		ll j = 0;
		while (1) {
			num2.push_back(a[j]);
			if (num2.size() == n)break;
			num2.push_back(a[n - 2 - j]);
			if (num2.size() == n)break;
			j++;
		}
	}
	ll ans = 0;
	rep(i, n - 1) {
		ans += abs(num[i + 1] - num[i]);
	}
	if (n % 2) {
		vector<ll>num2(1);
		num2[0] = target;
		ll j = 0;
		while (1) {
			num2.push_back(a[j]);
			if (num2.size() == n)break;
			num2.push_back(a[n - 2 - j]);
			if (num2.size() == n)break;
			j++;
		}
		ll res = 0;
		rep(i, n - 1) {
			res += abs(num2[i + 1] - num2[i]);
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
