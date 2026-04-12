/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> dp(n);
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1)
            dp[i] = a[i];
        else
            dp[i] = dp[i + 1] + a[i];
      		dp[i] %= MOD;
    }
    ll res = 0;
    for(int i = 0; i < n - 1; i++){
        ll temp = (a[i] * dp[i + 1]) % MOD;
        res = (res + temp) % MOD;
    }
    cout << res << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}