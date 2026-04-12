#include<bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr int mo = 1e9+7;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<60;
constexpr ll mo2 = 998244353;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(auto & b: a) cin>>b;
    vector<ll> dp(s+1);
    ll ret = 0;
    for(int i=0;i<n;++i){
        for(int j=s-a[i];j>=0;--j){
            if(j == 0)(dp[a[i]] += i+1)%=mo2;
            else (dp[a[i]+j] += dp[j])%=mo2;
        }
        ret += dp[s]%mo;
    }
    cout << ret%mo2 << endl;
    return 0;
}