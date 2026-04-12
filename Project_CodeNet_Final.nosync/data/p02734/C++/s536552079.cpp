#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep2(i,m,n) for(int i=int(m);i<int(n);i++)
#define drep2(i,m,n) for(int i=int(m-1);i>=int(n);i--)
#define rep(i,n) rep2(i,0,n)
#define drep (i,n) drep2(i,n,0)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
ll mod =998244353;

int main()
{
    int n,s;cin >>n>>s;
    int dp[n+1][s+1];
    rep(i,n+1)rep(j,s+1)dp[i][j]=0;
    int a[n];rep(i,n)cin >>a[i];
    rep(i,n){
        rep(j,s+1){
        dp[i+1][j]=dp[i][j];
        dp[i+1][j]%=mod;
        if(j-a[i]>=0)dp[i+1][j]+=dp[i][j-a[i]];
         dp[i+1][j]%=mod;
        if(j==a[i]||j==0)dp[i+1][j]++;
         dp[i+1][j]%=mod;
        }
    }
    ll ans=0;
    rep(i,n){
        ans+=dp[i+1][s];
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}
