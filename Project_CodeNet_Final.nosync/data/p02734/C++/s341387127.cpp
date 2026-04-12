#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    const ll MOD = 998244353;
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(s+1, vector<ll>(3,0)));
    dp.at(0).at(0).at(0) = 1;
    for(i = 0;i < n;++i){
        rep(j,s+1){
            dp.at(i+1).at(j).at(0) += dp.at(i).at(j).at(0);
            dp.at(i+1).at(j).at(0) %= MOD;
            dp.at(i+1).at(j).at(1) += dp.at(i).at(j).at(0) + dp.at(i).at(j).at(1);
            dp.at(i+1).at(j).at(1) %= MOD;
            dp.at(i+1).at(j).at(2) += dp.at(i).at(j).at(0) + dp.at(i).at(j).at(1) + dp.at(i).at(j).at(2);
            dp.at(i+1).at(j).at(2) %= MOD;
            if(j + a.at(i) <= s){
                ll tmp = j + a.at(i);
                dp.at(i+1).at(tmp).at(1) += dp.at(i).at(j).at(0) + dp.at(i).at(j).at(1);
                dp.at(i+1).at(tmp).at(1) %= MOD;
                dp.at(i+1).at(tmp).at(2) += dp.at(i).at(j).at(0) + dp.at(i).at(j).at(1);
                dp.at(i+1).at(tmp).at(2) %= MOD;
            }
        }
    }
    cout << dp.at(n).at(s).at(2)%MOD << endl;
    return 0;
}
