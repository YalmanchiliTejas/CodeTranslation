#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
ll dx[4]={0,0,1,-1};
ll dy[4]={-1,1,0,0};


void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<ll> suf(n,0);
    suf[n-1]=a[n-1];
    for(int i=n-2;i>0;i--)
    {
        suf[i]=suf[i+1]+a[i];
        suf[i]%=mod;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++)
    {
        ans+=(a[i]*suf[i+1]);
        ans%=mod;
    }
    cout<<ans;
    return;
}

int main()
{
	FAST;
    ll q;
    q=1;
    // cin>>q;
    while(q--)
        solve();
	return 0;
}