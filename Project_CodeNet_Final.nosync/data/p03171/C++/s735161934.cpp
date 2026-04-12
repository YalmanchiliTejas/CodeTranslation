#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF=1LL << 60;
int f(int startidx,int endidx,int t,vector<int> &a,vector<vector<int>> &dp){
    
    if(dp[startidx][endidx]!=INF){
        return dp[startidx][endidx];
    }
    if(startidx>=endidx){
        return dp[startidx][endidx]=0;
    }
    if(t==0){
    return dp[startidx][endidx]=max(a[startidx]+f(startidx+1,endidx,!t,a,dp),a[endidx-1]+f(startidx,endidx-1,!t,a,dp));
    }
    else{
    return dp[startidx][endidx]=min(f(startidx+1,endidx,!t,a,dp)-a[startidx],f(startidx,endidx-1,!t,a,dp)-a[endidx-1]);
    }
}

int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<f(0,n,0,a,dp)<<endl;
}
