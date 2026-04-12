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
const int MOD = int(1e9)+7;


int main()
{
    ll n;cin >>n;
    ll a[n];rep(i,n)cin >>a[i];
    ll k=n/2;
    ll ans;
    if(n%2==0){
        ll dp[k+1][2];rep(i,k+1)rep(j,2)dp[i][j]=0;
        rep(i,k){
            dp[i+1][1]=max(dp[i][1]+a[2*i+1],dp[i][0]+a[2*i+1]);
            dp[i+1][0]=dp[i][0]+a[2*i];
        }
        ans=max(dp[k][0],dp[k][1]);
    }
    else {
         ll dp[k+1][3];rep(i,k+1)rep(j,3)dp[i][j]=0;
        rep(i,k){
            dp[i+1][2]=max(max(dp[i][1]+a[2*i+2],dp[i][0]+a[2*i+2]),dp[i][2]+a[2*i+2]);
            dp[i+1][1]=max(dp[i][1]+a[2*i+1],dp[i][0]+a[2*i+1]);
            dp[i+1][0]=dp[i][0]+a[2*i];
        }
        ans=max(max(dp[k][0],dp[k][1]),dp[k][2]);
    }
    cout << ans << endl;
    return 0;
}
