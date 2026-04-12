#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
	ios;
	int n,i;
	ll ans=0,s=0, mod= (int)1e9+7;
	cin>>n;
	vector<ll> a(200005);
	for(i=0;i<n;i++) 
	{
		cin>>a[i];
		s=(s+a[i])%mod;
	}
//	cout<<s<<" ";
	for(i=0;i<n-1;i++)
	{
		s=(s-a[i]+mod)%mod;
		ans= (ans +  (a[i]*s)%mod)%mod;
//		cout<<s<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}