#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll MOD = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
ll max(ll a, ll b) { return (a > b) ? a : b; }


template<typename T, T MOD = 1000000007>
struct Mint {
	T v;

	Mint() : v(0) {}
	Mint(signed v) : v(v) {}
	Mint(ll t) { v = t % MOD; if (v < 0) v += MOD; }

	Mint pow(ll k) {
		Mint res(1), tmp(v);

		while (k) {

			if (k & 1) res *= tmp;

			tmp *= tmp;
			k >>= 1;
		}



		return res;
	}

	Mint inv() { return pow(MOD - 2); }

	Mint& operator=(Mint a) { if (a.v >= MOD) a.v %= MOD; v = a.v; return *this; }
	Mint& operator+=(Mint a) { v += a.v; if (v >= MOD) v -= MOD; return *this; }
	Mint& operator-=(Mint a) { v += MOD - a.v; if (v >= MOD) v -= MOD; return *this; }
	Mint& operator*=(Mint a) { v = 1LL * v * a.v % MOD; return *this; }
	Mint& operator/=(Mint a) { return (*this) *= a.inv(); }
	Mint operator+(Mint a) const { return Mint(v) += a; }
	Mint operator-(Mint a) const { return Mint(v) -= a; }
	Mint operator*(Mint a) const { return Mint(v) *= a; }
	Mint operator/(Mint a) const { return Mint(v) /= a; }

	Mint operator-() { return v ? MOD - v : v; }
	bool operator==(const Mint a) const { return v == a.v; }
	bool operator!=(const Mint a) const { return v != a.v; }
	bool operator < (const Mint a) const { return a < a.v; }


};

using M = Mint<ll>;

M Fact[2 * 100005];


int main() {
	
	ll n, m, k;
	cin >> n >> m >> k;
	Fact[0] = 1;
	rep(i, n*m+1) {
		Fact[i + 1] = Fact[i] * (i+1);
	}


	auto comb = [](ll a, ll b) { return Fact[a] / (Fact[b] * Fact[a - b]); };
	
	M ret = 0;
	rep(i, n) {
		ret += M(i) * M((n - i)) * M(m) * M(m);
	}
	rep(i, m) {
		ret += M(i) * M((m - i)) * M(n) * M(n);
	}

	cout <<  (comb(m*n - 2, k - 2) * ret).v << endl;

	return 0;
}