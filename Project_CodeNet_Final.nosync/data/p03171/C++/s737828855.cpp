#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#ifndef HOME
#define cerr if(0)cerr
#endif
const int N = 3005;
int dp[N][N][2];
int n;
int a[N];
int solve(int i,int j,int cur){
    if(i > j) return 0;

    int &ans = dp[i][j][cur];
    if(ans != -1) return ans;

    if(!cur){
        int res = -1e18;
        res = max(res,a[i] + solve(i+1,j,1));
        res = max(res,a[j] + solve(i,j-1,1));
        return ans = res;
    }else{
        int res = 1e18;
        res = min(res,-a[i] + solve(i+1,j,0));
        res = min(res,-a[j] + solve(i,j-1,0));
        return ans = res;
    }
    return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1,0)<<endl;
    return 0;
    
}

