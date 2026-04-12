#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db long double
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
const int mxn=3002;
int n;
int a[mxn];
int dp[mxn][mxn][2];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--)
    for (int j=i;j<=n;j++)
    {
        if (i==j) dp[i][j][0]=a[i],dp[i][j][1]=0;
        if (dp[i][j-1][1]+a[j]<dp[i+1][j][1]+a[i]) dp[i][j][0]=dp[i+1][j][1]+a[i],dp[i][j][1]=dp[i+1][j][0];
            else dp[i][j][0]=dp[i][j-1][1]+a[j],dp[i][j][1]=dp[i][j-1][0];
    }
    cout<<dp[1][n][0]-dp[1][n][1];
    return 0;
}