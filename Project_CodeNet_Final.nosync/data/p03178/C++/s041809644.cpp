#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[10005][105][2];
string s;
ll d;

ll solve(ll pos, ll sum, bool tight){
    if(pos==s.length()){
        return sum==0;
    }
    if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];

    ll ans=0;
    ll end = ((tight)?(s[pos]-'0'):9);
    for(ll i=0; i<=end; i++){
        ans = (ans + solve(pos+1,(sum+i)%d, tight&(i==end)))%mod;
    }
    return dp[pos][sum][tight]=ans;
}
int main() {
    cin>>s>>d;
    memset(dp,-1,sizeof (dp));
    cout<<(solve(0,0,1)-1 +mod)%mod<<endl;
    // cout<<(res-1 + mod)%mod<<endl;   // -1 coz one number whose sum will be equal to 0 is 0000000000000 and so on.
}
