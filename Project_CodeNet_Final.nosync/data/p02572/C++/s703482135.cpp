#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repr1(i, n) for (int i = n; i > 0; i--)
#define FOR(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
const ll MOD = 1000000007; // 10^9+7
const ll INF = 100000000;

int main(void){
    ll n;
    cin >> n;

    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);

    rep(i,n){
        cin >> a[i];
        a[i] %= MOD;
    }
    repr(i,n) b[i] = (a[i] + b[i+1]) % MOD;
    //rep(i,n) cout << b[i] << endl;

    ll ans=0;

    rep(i,n-1){
        ans = ( ans + ( a[i] * b[i+1] )%MOD) % MOD;
        //cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}