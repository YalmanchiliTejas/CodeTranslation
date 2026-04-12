#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    /*if(n&1) {
        int a1=0, a2=0;
        for(int i=0;i<n;i++) {
            if(i&1)
                a1+=arr[i];
            else
                a2+=arr[i];
        }
        cout<<max(a1,a2);
        return 0;
    }*/

    int a1=0;
    for(int i=0;i<n;i++) {
        if(i&1)
            a1+=arr[i];
    }

    int dp[n][4];
    for(int i=0;i<n;i++) {
        dp[i][0]=-1e18;
        dp[i][1]=-1e18;
        dp[i][2]=-1e18;
        dp[i][3]=-1e18;
    }
    dp[0][0]=arr[0];
    dp[1][0]=arr[1];
    for(int i=2;i<n;i++) {
        dp[i][0]=dp[i-2][0]+arr[i];
        if(i==2&&n%2==1) {
            dp[i][1]=arr[2];
        }
        if(i>2)
            dp[i][1]=max(dp[i-2][1]+arr[i], dp[i-3][0]+arr[i]);
        if(i>3&&n%2==1) {
            dp[i][2]=max(dp[i-4][0]+arr[i], dp[i-2][2]+arr[i]);
        }
        if(i>4) {
            dp[i][3]=max(dp[i-3][1]+arr[i], dp[i-2][3]+arr[i]);
        }
    }
    int ans=a1;
    ans=max(ans,dp[n-1][0]);
    ans=max(ans,dp[n-1][1]);
    if(n&1) {
        ans=max(ans, dp[n-2][2]);
        ans=max(ans,dp[n-1][3]);
    }
    if(n>1) {
        ans=max(ans,dp[n-2][0]);
    }

    cout<<ans;

    return 0;
}