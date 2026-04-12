//long time no ac
#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

#define     SPEED       ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define 	setprecn(x) cout<<fixed<<setprecision(x);
#define 	ll          long long int
#define 	pb          push_back
#define 	pll         pair<ll,ll>
#define 	vll         vector<ll>
#define 	ff          first
#define 	ss          second
#define 	all(a)      (a).begin(),(a).end()
#define 	sz(x)       (ll)x.size()
#define 	hell        1000000007
#define 	rep(i,n)    for(ll i=0;i<n;i++)
#define 	repe(i,a,b) for(ll i=a;i<b;i++)
#define 	lbnd        lower_bound
#define 	ubnd        upper_bound
#define 	bs          binary_search

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ll c=power(a,b/2);
	if(b%2==0)
		return((c%hell)*(c%hell))%hell;
	return ((((c%hell)*(c%hell))%hell)*(a%hell))%hell;
}

/********************************************************/
//	d.erase(unique(all(d)), d.end());




int main()
{
	SPEED;
	ll n,k,m,i,j,c=0,cs=0,t;
	t=1;

	// cin>>t;
	string s;
	while(t--)
	{
		// cs++;
		cin>>n;
		// n=s.length();
		ll a[n];
		rep(i,n)
		{
			cin>>a[i];
			if(a[i]>=c) c=a[i],cs++;
		}
		
		
		cout<<cs;
		if(t!=0)
	   		cout<<"\n";
	}
	return 0;
}