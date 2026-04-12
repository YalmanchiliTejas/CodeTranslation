#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5,D=105,mod=1e9+7;
string str;
ll d,n,dp[N][D][2];
ll solve(ll i,ll sum,bool flg){
    if(i==n)return sum==0;
    if(dp[i][sum][flg]!=-1)return dp[i][sum][flg];
    ll &ans = dp[i][sum][flg];
    ans = 0;
    ll s = 0 , e=9;
    if(!flg)e=(str[i]-'0');
    for(ll dig=s;dig<=e;dig++){
        ll nsum = sum + dig;
        nsum%=d;

        bool nflg = flg || (dig<(str[i]-'0'));
        ans = ans + solve(i+1,nsum,nflg);
        ans%=mod;
    }
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>str>>d;
    n=str.size();
    memset(dp,-1,sizeof(dp));
    cout<<( solve(0,0,0) - 1 + mod)%mod;
}