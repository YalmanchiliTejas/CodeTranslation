#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define pii pair<int,int>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,s; cin>>n>>s;
    int arr[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int dp[s+1][n+1]; fill(dp,0);
    for(int j=1;j<=n;j++){
        int temp=0;
        if(s>arr[j]) temp=dp[s-arr[j]][j-1];
        else if(s==arr[j]) temp=j;
        ans=(ans+temp*(n+1-j))%mod;
        for(int i=1;i<=s;i++){
            dp[i][j]=dp[i][j-1];
            if(arr[j]<=i) dp[i][j]=(dp[i][j]+dp[i-arr[j]][j-1])%mod;
        }
        if(arr[j]<=s) dp[arr[j]][j]=(dp[arr[j]][j]+j)%mod;
    }
    cout<<ans<<endl;
}