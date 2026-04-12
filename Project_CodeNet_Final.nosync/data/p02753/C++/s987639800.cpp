//author-jayesh parmar
#include <bits/stdc++.h>
#define ll 					long long
#define abs(x) 				x>0?x:(-x)
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define popb                pop_back
#define popf                pop_front
#define mp                  make_pair
#define mt                  make_tuple
#define ff                  first
#define ss                  second
#define vll                 vector<ll>
#define vvl                 vector<vll>
#define pll                 pair<ll,ll>
#define mll                 map<ll,ll>
#define ub                  upper_bound
#define lb                  lower_bound
#define bs                  binary_search
#define all(x)              x.begin(),x.end()
#define rall(x)             x.rbegin(),x.rend()
#define get(tup,ind)        get<ind>(tup)
#define sv(i,s,e,v) for(ll i=(s);i<(e);i++){int ip;,cin>>ip;,v.pb(ip);}   
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int32_t main() 
{
	fast
	string s;
	int a=0,b=0;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
			a++;
		else
			b++;
	}
	if(a && b)
		cout << "Yes"; 
	else
		cout << "No";

	return 0; 
}