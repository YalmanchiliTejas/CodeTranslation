#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)  for(ll i = 0; i < (n); ++i)
#define rep1(i,n)  for(ll i = 1;i <= (n); ++i)
#define pb push_back
#define M 1000000007
unordered_map<ll,ll>mp;

int main()
{
    fastIO
    ll n;
    cin>>n;
    ll v[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    ll suf[n+2];
    suf[n+1]=0;
    for(int i=n;i>=1;i--)
        suf[i]=(v[i]+suf[i+1])%M;
    ll res=0;
    for(ll i=1;i<=n;i++)
    {
        ll x=(v[i]*suf[i+1])%M;
        res=(res+x)%M;
    }
    cout<<res;
	return 0;
}
