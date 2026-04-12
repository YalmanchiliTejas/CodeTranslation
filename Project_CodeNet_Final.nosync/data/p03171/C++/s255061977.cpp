#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int INT_INF = 1e9;
const ll MOD = 1e9 + 7;
const int INT_MOD=1e9+7;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 0; i <= n; i++)
#define rrep(i,n) for(int i=n;i>0;i--)
#define RREP(i,n) for(int i=n;i>=0;i--)
typedef pair<int, int> Pi;
typedef pair<double, double> P;
ll dp[3003][3003]={};
signed main(){
    int n;cin>>n;
    int a[n]={};
    rep(i,n) cin>>a[i];
    RREP(i,n-1){
        for(int j=i;j<n;j++){
            if((n-i-j-1)%2==0){
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
            }else{
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}