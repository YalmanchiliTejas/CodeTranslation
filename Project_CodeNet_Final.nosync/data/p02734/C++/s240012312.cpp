#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t

const int MOD = 998244353;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,s;
    cin>>n>>s;
    int arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    int ans=0;
    int dp[n+1][s+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=s;j++) {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]<=s)
            dp[i][arr[i]]+=i;
        for(int j=0;j<=s;j++) {
            if(j+arr[i]<=s) {
                dp[i][j+arr[i]]+=dp[i-1][j];
                dp[i][j+arr[i]]%=MOD;
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
        ans+=(dp[i][s]*(n-i+1));
        ans%=MOD;
        dp[i][s]=0;
    }
    cout<<ans;

    return 0;
}