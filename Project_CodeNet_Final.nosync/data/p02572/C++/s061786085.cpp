#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pii pair<int,pi>
#define pl pair<ll,ll>
#define pll pair<ll,pl>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int I_LIMIT = 999999999;
ll L_LIMIT = 999999999999999999;
ll mod = 1e9+7;

void solve()
{
    ll n,i,ans=0;
    cin>>n;
    ll A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    
    ll pre[n+1];
    pre[n]=0;
    for(i=n-1;i>=0;i--)
        pre[i]=(pre[i+1]+A[i])%mod;
    
    for(i=0;i<n-1;i++)
        ans = (ans+A[i]*pre[i+1])%mod;
    
    cout<<ans<<endl;
}
int main()
{
    IOS;
    solve();
}
