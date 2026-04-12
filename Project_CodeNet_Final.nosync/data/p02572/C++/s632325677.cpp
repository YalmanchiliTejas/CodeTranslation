#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = (1e9+7); 
int main()
{
	ll n;ll sum = 0;
	cin>>n;ll pref[n];vector<ll>a;
	for(int i = 0; i<n; i++)
	{
		ll v;
		cin>>v;
		a.push_back(v);
		sum+=a[i];
		pref[i]=sum;
	}
	ll ans = 0;
	for(int i = 0; i<n; i++)
	{
		ll p = a[i];
		ll q = pref[n-1]-pref[i];
		ll z = ((p%m)*(q%m))%m;
		ans = ((ans%m)+(z%m))%m;
		
	}
  cout<<ans;
}