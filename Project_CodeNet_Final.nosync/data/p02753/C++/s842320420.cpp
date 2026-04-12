#include<bits/stdc++.h>

using namespace std;

using   ll=long long;
using   ld=long double;

#define fast           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl           "\n"
#define long long      int 
#define pb             push_back
#define mp             make_pair
#define ff             first
#define ss             second
#define pll            pair<ll,ll>
#define ALL(v)         v.begin(),v.end()
#define ALLR(v)        v.rbegin(),v.rend()
#define pii            3.14159265358979323
#define inf 		   LLONG_MAX
#define ones(x)		   __builtin_popcount(x)

void solve()
{
	string s;
	
	cin>>s;
	
	if(s !="AAA" && s!="BBB")
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No";
	}
}
 
signed main()
{
 
    fast;
 
    ll t;
    
    t=1;
    
    //cin>>t;
    
    while(t--)
    {
        solve();
    }
 
    return 0;
}