#include <bits/stdc++.h>
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;

ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}
using namespace std;

int main() 
{
	string ss= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	fast;
	ll n; string s; cin>>n; vector<string>v;
	for(ll i = 0; i < n; i++)
	{
		cin>>s; v.pb(s);
		if(s.length() < ss.length()) ss = s;
		else if(s.length() == ss.length())
		{
			int c = s.compare(ss);
			if(c < 0) ss = s;
		}
	} ll flag = 0;
	for(ll i = 0; i < ss.size(); i++)
	{
		char c = ss[i]; flag = 1;
		for(ll j = 0; j < n; j++)
		{
			size_t ttt = v[j].find(c);
			if( ttt == string::npos) flag = 0;
			else
			{
				v[j].erase(ttt,1);
			}
		}
		if(flag == 0)
			ss[i] = '.';	
	} 
	sort(ss.begin(),ss.end());
	for(ll i = 0; i < ss.size(); i++)
	{
		if(ss[i] == '.') continue;
		else cout << ss[i];
	}
  	return 0; 
}