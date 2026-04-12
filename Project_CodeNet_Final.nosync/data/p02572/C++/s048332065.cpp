/* ****Ragnar7 _Lawliet_**** */
/* First, solve the problem.Then write the code. */
#include<bits/stdc++.h>
#define ll          long long
#define ld 			long double
#define hell        1000000007
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen ("input.txt","r",stdin);
	// freopen ("output.txt","w",stdout);
	#endif
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll s = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			s+=v[i];
		}
		ll ans =0 ;
		s=s%hell;
		for(ll i=0;i<n;i++)
		{
			s = ((s-v[i])%hell+hell)%hell;
			ans = (ans+v[i]*s)%hell;
			
		}
		cout<<ans%hell;
		
	}

	
	time
	return 0;
}