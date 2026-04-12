#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2, vector<ll>(2, -1e9)));
    dp.at(0).at(1).at(1) = a.at(0); 
    dp.at(0).at(0).at(1) = 0;
    dp.at(0).at(0).at(0) = 0;

    dp.at(1).at(1).at(1) = a.at(1);
    dp.at(1).at(1).at(0) = a.at(0);
    dp.at(1).at(0).at(0) = 0;
    for(i = 2;i < n;++i){
        j = i+1;
        if(j%2 == 0){
            dp.at(i).at(1).at(1) = dp.at(i-1).at(0).at(0) + a.at(i);
            dp.at(i).at(1).at(0) = dp.at(i-1).at(1).at(1);
            dp.at(i).at(0).at(0) = max(dp.at(i-1).at(0).at(1), dp.at(i-1).at(0).at(0)); 
        }else if(j%2 == 1){
            dp.at(i).at(1).at(1) = dp.at(i-1).at(1).at(0) + a.at(i);
            dp.at(i).at(0).at(1) = dp.at(i-1).at(0).at(0) + a.at(i);
            dp.at(i).at(0).at(0) = max(dp.at(i-1).at(1).at(1), dp.at(i-1).at(1).at(0)); 
        }
    }
    if(n%2 == 0){
        cout << max(dp.at(n-1).at(1).at(1), dp.at(n-1).at(1).at(0)) << endl;
    }else{
        cout << max(dp.at(n-1).at(0).at(1), dp.at(n-1).at(0).at(0)) << endl;
    }
    return 0;
}