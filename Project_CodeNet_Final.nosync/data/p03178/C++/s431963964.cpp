#include <bits/stdc++.h>
using namespace std;

#define TC int T;cin>>T;for(int tc=1;tc<=T;++tc)

using ll=long long;
constexpr ll mod=1000000007;

ll dp[10001][100][2];
string k;
int d;

ll getWays(int i, int j, bool lim){
    if(i>=k.size())return j==0;
    if(dp[i][j][lim]!=-1) return dp[i][j][lim];
    int max_dig = 9;
    if(lim) max_dig = k[i]-'0';
    ll ways=0;
    for(int k=0;k<=max_dig;++k){
        ways=(ways+getWays(i+1,(j+d-k)%d,lim&&(k==max_dig)))%mod;
    }
    dp[i][j][lim]=ways;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>k>>d;
    memset(dp,(ll)-1,sizeof(dp));
    ll ans = (getWays(0,0,true)+mod-1)%mod;
    cout<<ans<<endl;
    
    return 0;
}