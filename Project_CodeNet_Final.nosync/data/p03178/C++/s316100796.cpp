#include<bits/stdc++.h>
typedef long long int ll;
#define endl '\n'
using namespace std;
ll dp[100009][105][2],D;
const ll mod=1e9+7;
string s;
ll solve(int i = 0, int sum = 0, bool tight = 1){
    if(i == s.size())
        return (sum%D==0);
    if(dp[i][sum%D][tight] != -1)
        return dp[i][sum%D][tight];
    ll ret = 0;
    for(int d = 0; d <= (tight ? s[i] - '0' : 9); d++)
        ret += solve(i + 1, (sum + d)%D, d == s[i] - '0' ? tight : 0);
    return dp[i][sum%D][tight] = ret%mod;
}

int main(){
    //ios_base::sync_with_stdio(false),cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>s>>D;
    ll ans=solve();
    ans--;
    ans=(ans+mod)%mod;
    cout<<ans<<endl;

    return 0;
}
