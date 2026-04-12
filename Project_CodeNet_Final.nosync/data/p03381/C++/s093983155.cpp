#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define F first
#define S second
#define ld long double
#define built __builtin_popcountll
#define mst(a,i) memset(a,i,sizeof(a))
#define all(x) x.begin(),x.end()
#define itit(it,a) for(auto it=(a).begin(); it!=(a).end(); it++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>b; i--)
#define reprr(i,a,b) for(ll i=a; i>=b; i--)
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
ll max3(ll x,ll y,ll z) {return max(max(x,y),z);}
ll min3(ll x,ll y,ll z) {return min(min(x,y),z);}
const ll M=2e5+10,M2=1e6+10,mod=1e9+7,inf=1e17+10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll x[n];
	rep(i,0,n) cin >> x[i];

	ll y[n];
	rep(i,0,n) y[i]=x[i];

	sort(y,y+n);
	reverse(y,y+n);

	ll z=y[n/2-1];

	rep(i,0,n){
		if(x[i]<z) cout << z << "\n";
		else cout << y[n/2] << "\n";
	}
	return 0;
}
/* The judge is never wrong! Your code is buggy
   Look for:
 * * Read the problem carefully.
 * * Don't forget to sort(), mod, ll!!!!
 * * Initial value = +/- infinity instead of zero!!!
 * * an easier and alternate approach
 * * read the problem statement carefully
 * * if concept is correct and still WA, try with a different implementation
 * * special cases (n=1?)
 * * overflow (ll vs int?)
 * * array bounds
 * * if you have no idea just guess the appropriate well-known algorithm instead of doing nothing :/
 */
