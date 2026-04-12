#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int lli;
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define F first
#define S second
#define forn(i,n) for(int i = 0; i<n; i++)
#define forab(i,a,b) for(int i = a; i<b; i++)
#define forll(i,a,b) for(lli i = a; i<b; i++)
#define mp make_pair
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define debug(x) cout<<#x<<" : "<<x<<endl
#define all(x) x.begin(),x.end()
#define printv(v) for(auto it : v) cout<<it<<" ";cout<<endl;
#define prec(n) fixed<<setprecision(n)
const int mod1 = 1000000007;
const int mod2 = 998244353;
const int N = 1e5;

int main()
{
	optimize

	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	#endif

	lli n,x,m;
	cin>>n>>x>>m;
	lli ans = 0;
	lli a = x;
	lli b = x;

	vi rem;

	while(find(all(rem), b) == rem.end())
	{
		rem.pb(b);
		ans += b;
		b = (b*b)%m;
	}

	int sub = 0;
	lli anssub = 0;
	for(int x : rem)
	{
		if(x != b)
		{
			anssub += x;
			sub++;
		}
		else
			break;
	}


	int cycsz = rem.size()-sub;

	ans = anssub + ((n-sub)/cycsz) * (ans-anssub);

	forn(i, (n-sub)%cycsz)
	{
		ans += b;
		b = (b*b)%m;
	}

	cout<<ans<<endl;

	


	return 0;
}