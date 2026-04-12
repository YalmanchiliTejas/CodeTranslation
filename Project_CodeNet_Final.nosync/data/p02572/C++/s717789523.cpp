#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define vv vector<lli>
#define vp vector<pair<lli,lli>>
#define vpp vector<pair<lli,pair<lli,lli>>>
#define lims(w) (w).begin(),(w).end()
#define rlims(w) (w).rbegin(),(w).rend()
#define pb push_back
#define mp make_pair
#define f(i,a,b) for(lli i=a;i<b;i++)
#define ff first
#define ss second
#define sz(a) (lli)(a.size())
lli inf = (1e18 + 2);
lli mod = (1e9 + 7);

int main()
{
	lli n;
	cin>>n;
	lli sum = 0;
	lli a[n+1];
	f(i,0,n)
		cin>>a[i];
	lli s[n+1];
	s[n-1] = a[n-1];

	for(lli i=n-2;i>=0;i--)
		s[i] = (s[i+1] + a[i] + (2*mod)) % mod;
	
	lli prod;

	f(i,0,n-1)
	{
		prod = (a[i] * s[i+1]) % mod;
		sum = (sum + prod) % mod;
	}
	
	cout<<sum<<endl;
	return 0;
}
