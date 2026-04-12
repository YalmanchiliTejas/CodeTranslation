#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll=long long;

int main(){
    const ll INF=LLONG_MAX/2;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ret=0;
    if(n%2==0){
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(2,-INF)));
        dp[0][0][0]=0;
        dp[0][1][1]=a[0];
        for(int i=1;i<n;i++){
            if(i%2==0){
                dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][1][1]);
                dp[i][0][1]=-INF;
                dp[i][1][0]=-INF;
                dp[i][1][1]=dp[i-1][0][1]+a[i];
            }else{
                dp[i][0][0]=-INF;
                dp[i][0][1]=dp[i-1][1][1];
                dp[i][1][0]=-INF;
                dp[i][1][1]=dp[i-1][0][0]+a[i];
            }
        }
        ret=max(dp[n-1][0][1],dp[n-1][1][1]);
    }else{
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(2,-INF)));
        dp[0][0][0]=0;
        dp[0][1][1]=a[0];
        for(int i=1;i<n;i++){
            if(i%2==0){
                dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][1][1]);
                dp[i][0][1]=-INF;
                dp[i][1][0]=dp[i-1][0][0]+a[i];
                dp[i][1][1]=dp[i-1][0][1]+a[i];
            }else{
                dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][1][0]);
                dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]);
                dp[i][1][0]=-INF;
                dp[i][1][1]=dp[i-1][0][0]+a[i];
            }
        }
        ret=max(dp[n-1][0][0],dp[n-1][1][0]);
    }
    cout<<ret<<endl;
}
