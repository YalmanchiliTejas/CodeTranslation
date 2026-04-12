#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define VVV vector<vector<vector<long long>>>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main() {
    ll n;
    cin>>n;
    V a(n);
    rep(i,n)cin>>a[i];
    if(n%2==1){
        VVV dp(n+1,VV(3,V(2,-1e10)));
        rep(i,n){
            rep(j,3){
                if(i+1==2&&j>0)continue;
                if(i+1==3&&j>1)continue;
                dp[i+1][j][0]=dp[i][j][1];
                if(j>0)dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j-1][0]);
                if(dp[i][j][0]==-1e10){
                    dp[i+1][j][1]=a[i];
                }else{
                    dp[i+1][j][1]=dp[i][j][0]+a[i];
                }
            }
        }
        cout<<max({dp[n][0][0],dp[n][1][0],dp[n][1][1],dp[n][2][1]})<<endl;
    }else{
        VVV dp(n+1,VV(2,V(2,-1e10)));
        rep(i,n){
            rep(j,2){
                if(i+1==2&&j>0)continue;
                dp[i+1][j][0]=dp[i][j][1];
                if(j>0)dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j-1][0]);
                if(dp[i][j][0]==-1e10){
                    dp[i+1][j][1]=a[i];
                }else{
                    dp[i+1][j][1]=dp[i][j][0]+a[i];
                }
            }
        }
        cout<<max({dp[n][0][0],dp[n][0][1],dp[n][1][1]})<<endl;
    }
}
