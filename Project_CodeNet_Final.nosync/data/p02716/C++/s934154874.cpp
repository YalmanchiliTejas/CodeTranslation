#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int INF=2*1e9;
ll dp[200005],a[200005],sum[200005];
int main()
{
    ll n;
    cin>>n;
    rep1(i,n) cin>>a[i];
    sum[1]=a[1];
    for(int i=2;i<=n;i++) sum[i]=sum[i-2]+a[i];
    for(int i=2;i<=n;i++)
    {
        if(i%2==1) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else dp[i]=max(sum[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n];
}

