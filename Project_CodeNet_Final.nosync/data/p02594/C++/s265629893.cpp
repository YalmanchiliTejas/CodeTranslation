#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a.size())
#define pll pair<ll,ll>
#define all(v) v.begin(), v.end()
#define FOR(i, a, b) for(i=a;i<b;i++)

set<ll>::iterator it;
ll mod = 1000000007;
ll power(ll a,ll b)
{
	ll p = 1;
	a = a%mod;
	while(b>0)
	{
		if(b%2==1)
			p=((p%mod)*(a%mod))%mod;
		b=b>>1;
		a=((a%mod)*(a%mod))%mod;
	}
	return p;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	if(n>=30)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}