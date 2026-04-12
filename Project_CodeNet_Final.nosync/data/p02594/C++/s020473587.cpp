#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef set<int> si;
typedef set<vi> svi;
typedef set<ll> sll;
typedef set<vll> svll;
typedef set<pii> spii;
typedef set<vpii> svpii;
typedef set<pll> spll;
typedef set<vpll> svpll;
typedef vector<si> vsi;
typedef vector<sll> vsll;
typedef vector<spii> vspii;
typedef vector<spll> vspll;
#define ft first
#define sc second
#define pb push_back
#define ins insert
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define sortarr(a,n) sort(a,a+n)
#define tt ll tc; cin >> tc; while(tc--)
#define rep(var,start,end,interval) for(ll var=start;(interval>0 and var<end) or (interval<0 and var>end);var+=interval)
#define each(x,v) for(auto x : v)
#define takearr0(a,n) rep(z,0,n,1) cin >> a[z];
#define takearr1(a,n) rep(z,1,n+1,1) cin >> a[z];

int main()
{
	io;
	ll x;
	cin >> x;
	if(x >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}