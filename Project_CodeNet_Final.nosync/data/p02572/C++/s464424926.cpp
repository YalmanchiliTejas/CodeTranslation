#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F0R(i, a) for (int i = 0; i < (a); i++)
const int mod = 1e9 + 7;
const char nl = '\n';

ll binpow(ll x, ll n){
    if(n == 0) return 1;
    if(n % 2 == 0) return binpow(x * x % mod, n / 2);
    else return x * binpow(x, n - 1) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll tmp1 = 0, tmp2 = 0;
    F0R(i, n){
        ll a;
        cin >> a;
        tmp1 = (tmp1 + a) % mod;
        tmp2 = (tmp2 + a * a % mod) % mod;
    }
    tmp1 = tmp1 * tmp1 % mod;
    cout << (tmp1 - tmp2 + mod) % mod * binpow(2, mod - 2) % mod << nl;
    return 0;
}