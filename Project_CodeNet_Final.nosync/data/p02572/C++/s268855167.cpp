#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (ll i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i <= (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) { if (a < b) { return b; } return a; }

template<class T>
bool chmin(T &a, const T &b) { if (a > b) { a = b; return a; } return a; }

const int MOD = 1000000007;
int main() {
    ll n; cin >> n;
    vector<ll> a(n), s(n+1); 

    rep(i, n) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    ll ans = 0;
    rep(i, n) {
        ll sum = (s[n] - s[i+1])%MOD;
        ans += a[i] * sum;
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}