#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define nn          3001
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
int dp[nn][nn],a[nn];

int solve(int i,int j,int turn){
    if(i>j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(turn == 1)
        return dp[i][j] = max(a[i] + solve(i+1,j,0), a[j] + solve(i,j-1,0));
    
    else
        return dp[i][j] = min(solve(i+1,j,1), solve(i,j-1,1));
}

int32_t main() {
    FAST;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum += a[i];
    }

    cout<<2*solve(1,n,1) - sum;
}
