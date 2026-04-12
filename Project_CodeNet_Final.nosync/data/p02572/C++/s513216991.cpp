#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define t_case ll test;cin>>test;while(test--)
#define left(nod) 2*nod
#define right(nod) 2*nod+1
#define ss second
#define ff first
#define pb push_back
#define pll pair<ll,ll>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define deb(a) cout<<#a<<": "<<a;cout<<endl;
#define deba(a...) cout<<endl;cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;

int main()
{
	FAST;//not faster than scanf printf
	
	ll n;cin>>n;ll a[200009];
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	ll p[200009];p[n+1]=0;ll mo=1e9+7;
	for(ll i=n;i>=1;i--)p[i]=(p[i+1]+a[i])%mo;
	ll s=0;
	for(ll i=1;i<=n-1;i++)
	{
		s+=(a[i]*p[i+1])%mo;s%=mo;
		
	}
	
	cout<<s;
	
}
