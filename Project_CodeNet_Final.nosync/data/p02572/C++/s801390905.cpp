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
const ld pi = 3.141592653589793238;

/*bool IsPrime(ll num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) { // 素数ではない
			return false;
		}
	}
	// 素数である
	return true;
}*/
/*ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/
/*ll keta(ll n) {
	ll res = 0;
	while (n >= 1) {
		res += n % 10; n /= 10;
	}
	return res;
}*/
/*ll modpow(ll x, ll y, ll mod) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}*/
/*ll nCk(ll n, ll k) {
	ll a = 1, b = 1;
	for (int h = n - k + 1; h <= n; h++) { a *= h; a %= mod; }
	for (int h = 1; h <= k; h++) { b *= h; b %= mod; }
	return a * modpow(b, mod - 2) % mod;
}*/
//printf("%.10f\n", n);

ll test[223456], rui[223456];
signed main() {
	string s, t;
	ll n, m, k, a, b, c, cnt = 0, ans = 0;
	cin >> n;
	rep(i, n) {
		cin >> test[i];
	}
	for (int h = n - 1; h >= 0; h--) {
		rui[h] = (rui[h + 1] + test[h]) % mod;
	}
	rep(i, n) {
		ans += (rui[i + 1] * test[i]) % mod; ans %= mod;
		
	}
	cout << ans << endl;
	return 0;
}