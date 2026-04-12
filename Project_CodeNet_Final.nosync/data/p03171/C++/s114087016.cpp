#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;

#define pub push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define umap unordered_map
#define uset unordered_set

#define forn(i, n)     for(ll i = 0; i< (ll)n; i++)
#define forf(i, x, y)  for(ll i=(x); i<=(ll)y; i++)
#define forb(i, x, y)  for(ll i=(x); i>=(ll)y; i--)
#define lpt() 		   ll T; std::cin>>T; while(T--)

#define nl "\n"
#define newl std::cout<<"\n";
#define bug(x) std::cerr<<"debug "<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(),x.end()
#define fastio() ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

template<typename X> std::ostream& operator<< (std::ostream& out, std::vector<X> v)
{ for(auto &i : v) out<<i<<" "; return out; }
template<typename X, typename Y> std::ostream& operator<< (std::ostream& out, std::pair<X,Y> p)
{ out<<p.first<<" "<<p.second; return out; }

static const long long mod = 1000000007;

using namespace std;

ll n;
vll a;
ll dp[3005][3005];

ll x(ll i,ll j)
{
	ll &k = dp[i][j];
	if(j-i<0)
		return 0;
	if(k!=-1)
		return k;
	if(j==i)
		return k=a[i];
	return k = max(a[i]-x(i+1,j) , a[j]-x(i,j-1));
}

int main()
{fastio()
	
	cin>>n;
	a.resize(n);
	forn(i,n)
		cin>>a[i];
	memset(dp,-1,sizeof dp);
	cout<<x(0,n-1)<<nl;

return 0;}
