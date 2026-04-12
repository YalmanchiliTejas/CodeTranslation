#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll n;
vector<ll> a(3000);
vector<vector<ll>> dp(3010,vector<ll>(3010,1e14));

ll solve(ll l, ll r, ll times)
{
    if(times == n) return 0;
    if(dp.at(l).at(r) != 1e14) return dp.at(l).at(r);
    ll res;
    if(times%2 == 0){
        res = max(solve(l+1,r, times+1) + a.at(l), solve(l,r-1, times+1) + a.at(r));
    }else{
        res = min(solve(l+1,r, times+1) - a.at(l), solve(l,r-1, times+1) - a.at(r));
    }
    return dp.at(l).at(r) =  res;
}

int main()
{
    ll i,j,k;
    
    cin >> n;
    
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll ans = solve(0, n-1, 0);
    cout << ans << endl;
    return 0;
}