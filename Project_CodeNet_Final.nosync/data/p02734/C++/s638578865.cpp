#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int M = 998244353;
ll dp[3005],a[3005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=a[i];j--) dp[j] = (dp[j]+dp[j-a[i]])%M;
        dp[a[i]] = (dp[a[i]]+i)%M;
        ans = (ans+dp[s]*(n-i+1))%M;
        dp[s] = 0;
    }
    cout<<ans<<endl;
    return 0;
}
