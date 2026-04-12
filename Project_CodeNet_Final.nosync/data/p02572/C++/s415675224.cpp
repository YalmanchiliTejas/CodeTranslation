#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;


int main()
{
    ll t;
    ll mod=1e9+7;

        ll n;
        cin>>n;
        ll a[n+5]={0},cum[n+5]={0};

        fr(i,0,n)cin>>a[i];
        ll ans=0;
        fr(i,0,n)
        {
            cum[i+1]=cum[i]+a[i];
        }

        fr(i,0,n)
        {
            ans=ans%mod+(cum[n]-cum[i+1])%mod*a[i]%mod;
           // cout<<cum[n]-cum[i+1]<<endl;
           // cout<<ans<<endl;
        }

        cout<<ans<<endl;


}

























