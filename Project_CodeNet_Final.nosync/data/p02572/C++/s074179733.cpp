#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll n; cin >> n;
    ll sum = 0;
    ll ans = 0;
    vector<ll> a(n);

    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }

    rep(i,n-1){
        sum -= a[i];

        ans = (ans%MOD + ((a[i]%MOD)*(sum%MOD))%MOD)%MOD;
    }

    cout << ans;
}
