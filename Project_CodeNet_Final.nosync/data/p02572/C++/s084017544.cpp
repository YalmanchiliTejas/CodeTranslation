#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
typedef long long ll;
using namespace std;

int main()
{
 ll n,sum=0; cin>>n;
 ll a[n];
 ll s=0;
 vector<ll>v;
 for(ll i=0;i<n;i++)
 {
     cin>>a[i];
     s+=a[i];
     v.push_back(s);
 }
 ll k=v[n-1];
 ll ans=0;
 ll x;
 ll mod=1000000007;
 for(ll i=0;i<n;i++)
 {
     x=((a[i]%mod)*((k-v[i])%mod))%mod;
     ans=((ans%mod)+(x))%mod;
}
cout<<ans<<endl;
}