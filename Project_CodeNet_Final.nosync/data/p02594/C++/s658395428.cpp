#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll md = 1000000007;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
vl p, fac(2, 1), ifac(2, 1);

ll add(ll a, ll b) {
    return (a%md + b%md + md) % md;
}

ll mul(ll a, ll b) {
    return ( (a%md) * (b%md) ) % md;
}

ll power(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = ((res%mod) * (x%mod))%mod;
        n = (n >> 1);
        x = ((x%mod) * (x%mod))%mod;
    }
    return res;
}

void cachefact(ll lim, ll mod = md) {
    for(int i = 2; i <= lim; i++) {
        ifac.push_back((ifac[mod%i] * (mod - mod/i) % mod)%mod);
    }
    for(ll i = 2; i <= lim; i++) {
        fac.push_back((fac[i-1] * i)%mod);
        ifac[i] = (ifac[i-1] * ifac[i])%mod;
    }
}

ll C(int n, int r) {
    if(n < r) return 0;
    return mul(fac[n], mul(ifac[r], ifac[n-r]));
}

ll P(int n, int r) {
	if(n < r) return 0;
	return mul(fac[n], ifac[n-r]);
}

ll mod_fac(ll n, ll p) {
	return fac[n] * power(power(p, n/p), md - 2) % md * power(fac[n/p], md - 2) % md;
}

void multiply(vvl &F, vvl &R, ll N) {
	vvl temp(N, vl (N, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				temp[i][j] = add(temp[i][j], mul(F[i][k], R[k][j]));
			}
		}
	}
	F = temp;
}

void mpow(vvl &F, ll N, ll n) {
	vvl res(N, vl (N, 0));
	for(int i = 0; i < N; i++) res[i][i] = 1;
	while(n) {
		if(n & 1) multiply(res, F, N);
		multiply(F, F, N);
		n /= 2;
	}
	F = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    if(x >= 30) {
    	cout << "Yes\n";
    } else {
    	cout << "No\n";
    }
    return 0;
}