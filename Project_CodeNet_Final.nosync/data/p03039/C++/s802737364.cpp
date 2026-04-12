#pragma once

#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ll mod = 1000000007;

ll mpow(ll x, ll n) {
	ll ans = 1; x %= mod;
	while (n != 0) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

class Factorial {
private:
	vector<ll> fac;
	vector<ll> ifac;
public:

	Factorial(ll N) {
		fac.push_back(1);
		for (int i = 0; i < N; i++) fac.push_back(fac[i] * (i + 1) % mod);
		ifac.resize(N + 1);
		ifac[N] = inv_mod(fac[N]);
		for (int i = 0; i < N; i++) ifac[N - 1 - i] = (ifac[N - i] * (N - i)) % mod;
	}

	ll fact(ll a) { return fac[a]; }
	ll ifact(ll a) { return ifac[a]; }

	ll cmb(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		ll tmp = ifact(a - b) * ifact(b) % mod;
		return tmp * fac[a] % mod;
	}
	ll per(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		return fac[a] * ifac[a - b] % mod;
	}
};

int main(void)
{
	ll n, m, k;
	cin >> n >> m >> k;
	Factorial f(n * m);
	ll sum = 0;
	//x
	{
		ll xSum = 0;
		rep(i, m) {
			(xSum += ((m - i) * i) % mod) %= mod;
		}
		ll n2 = n * n % mod;
		(xSum *= n2) %= mod;
		//1...n * (m-1) * n * 1;
		//2...n * (m-2) * n * 2;
		sum += xSum;
	}
	//y
	{
		ll ySum = 0;
		rep(i, n) {
			(ySum += ((n - i) * i) % mod) %= mod;
		}
		ll m2 = m * m % mod;
		(ySum *= m2) %= mod;
		//1...n * (m-1) * n * 1;
		//2...n * (m-2) * n * 2;
		sum += ySum;
	}
	(sum *= f.cmb(n * m - 2, k - 2) % mod) %= mod;
	cout << sum<< endl;
	return 0;
}
