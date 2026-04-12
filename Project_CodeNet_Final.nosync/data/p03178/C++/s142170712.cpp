#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
string k;
ll d;
ll dp[20000][500][2];

ll solve(ll n,ll md,ll s){
    if((n==k.length())&&(md==0))
        return 1;
    if(n==k.length())
        return 0;
    if(dp[n][md][s]!=-1)
        return dp[n][md][s];
    dp[n][md][s]=0;
    int mx=(s==0?k[n]:'9')-'0';
    for(ll i=0;i<=mx;i++){
        ll nmd=(md+i)%d;
        ll ns=(s||(i<mx))?1:0;
        dp[n][md][s]=(dp[n][md][s]+solve(n+1,nmd,ns))%mod;
    }
    return dp[n][md][s];
}
int main(){
    cin>>k>>d;
    for(ll i=0;i<=k.length();i++)
        for(ll j=0;j<d;j++)
            dp[i][j][0]=dp[i][j][1]=-1;
    cout<<((solve(0,0,0)+mod-1)%mod)<<endl;
}
