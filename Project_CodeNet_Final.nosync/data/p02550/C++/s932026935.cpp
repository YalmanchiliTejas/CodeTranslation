#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ll MOD = 998244353;
const ld pi = 3.141592653589793238;

bool isprime(int p) {
	if (p == 1) return false;
	for (int i = 2; i < p; i++) {
		if (p % i == 0) return false;
	}
	return true;
}
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll keta(ll n) {
	ll res = 0;
	while (n >= 1) {
		res += n % 10; n /= 10;
	}
	return res;
}
ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}
ll nCk(ll n, ll k) {
	ll a = 1, b = 1;
	for (int h = n - k + 1; h <= n; h++) { a *= h; a %= mod; }
	for (int h = 1; h <= k; h++) { b *= h; b %= mod; }
	return a * modpow(b, mod - 2) % mod;
}
//printf("%.10f\n", n);


signed main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s, t;
	ll n, x, m, cnt = 0, ans = 0, first = 0, rupe = 0, ac = 0;
	cin >> n >> x >> m;
	map<ll, ll> test, rui, ok;//okは場所
	ans += x; test[1] = x; rui[1] = x; ok[x] = 1;
	for (int h = 2; h <= n; h++) {
		test[h] = (test[h - 1] * test[h - 1]) % m;
		if (ok[test[h]] == 0) { rui[h] = test[h] + rui[h - 1]; ok[test[h]] = h; }
		else {
			cnt = rui[h - 1] - rui[ok[test[h]] - 1]; rupe = h - ok[test[h]];
			ans = rui[ok[test[h]]]; first = ok[test[h]]; ac = ok[test[h]]; break;
		}
		if (h == n) { cout << rui[n] << endl; return 0; }
	}
	ll sum = 0;
	if (rupe == 0) { cout << ans << endl; return 0; }
	while (true) {
		if (first + rupe <= n) {
			ll yuu = (n - first) / rupe;
			ans += yuu * cnt; first += rupe * yuu;
		}
		else { ans += test[ac + sum + 1]; sum++; first++; }
		if (first == n) { break; }
		//ans %= m;
	}
	cout << ans << endl;
	return 0;
}