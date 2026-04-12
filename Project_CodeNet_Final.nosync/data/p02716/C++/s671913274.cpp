#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define all(X) X.begin(),X.end()

// for pair comparison function(ascending order) use return (i1.ff < i2.ff);

/* string operations :
   str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
   str.substr (x) : returns a substring str[x],... end of string
   str.find(qtr) : returns the first occurenece of qtr in str */

const int M = (1<<20)+5;
const int md = 1e9+7;

ll pwr(ll a,ll n,ll m)
{
	ll p=1;
	while(n>0)
	{
		if(n%2==1)
			p=(p*a)%m;
		a=(a*a)%m;
		n=n/2;
	}
	return p;
}

ll ar[M],ev[M],od[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll f=0,s=0,ans=0,i,j,k,n,mn;

	cin >> n;
	for(i=1;i<=n;++i)
		cin >> ar[i];

	if(n%2 == 0)
	{
		for(i=1;i<=n;i+=2)
			f += ar[i];
		ans = f;
		for(i=n-1;i>=1;i-=2)
		{
			f = f-ar[i]+ar[i+1];
			ans = max(f,ans);
		}
		cout << ans << "\n";
		return 0;
	}
	else if(n == 3)
	{
		cout << max({ar[1],ar[2],ar[3]}) << "\n";
		return 0;
	}

	for(i=1;i<=n-2;i+=2)
		f += ar[i];
	s = ans = f;
	// cout << ans << "\n";
	for(i=n-2;i>=1;i-=2)
	{
		f = f-ar[i]+ar[i+1];
		ans = max(f,ans);
	}
	// cout << ans << "\n";	
	f = s;
	for(i=n-2;i>=1;i-=2)
	{
		f = f-ar[i]+ar[i+2];
		ans = max(f,ans);
	}
	// cout << ans << "\n";
	f = s+ar[n];	

	od[1] = ar[1];
	for(i=2;i<=n;++i)
	{
		if(i%2)
		{
			od[i] = od[i-2]+ar[i];
			ev[i] = ev[i-1];
		}
		else
		{
			ev[i] = ev[i-2]+ar[i];
			od[i] = od[i-1];
		}
	}

	mn = 1e18;
	for(i=2;i<=n;i+=2)
	{
		mn = min(mn,ev[i-1]-od[i-2]);
		ans = max(ans,f+ev[i]-od[i+1]-mn);
	}

	cout << ans << "\n";
	return 0;
}




	