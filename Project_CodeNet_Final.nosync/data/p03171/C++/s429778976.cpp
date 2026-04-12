#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mx 1e18
#define mod 1000000007
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll powe(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return powe(((x%mod)*(x%mod))%mod,n/2);
    else                             //n is odd
        return ((x%mod*(powe(((x%mod)*(x%mod))%mod,(n-1)/2))%mod)%mod);
}
int main()
{io
int n;cin>>n;vector<ll>a(n);vector<vector<ll>>dp(3005,vector<ll>(3005,0));
for(int i=0;i<n;i++)cin>>a[i];
for(int i=n-1;i>=0;i--)
{
    for(int j=i;j<=n-1;j++)
    {
        if(i==j)dp[i][j]=a[i];
        else
        dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    }
}
cout<<dp[0][n-1]<<endl;


}