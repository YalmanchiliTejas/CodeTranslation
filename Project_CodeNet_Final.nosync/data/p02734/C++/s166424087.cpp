
// Problem : F - Knapsack for All Segments
// Contest : AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
const ll mod = 998244353;

#define speedup_IO      ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(i,a,n)     for(ll i = a; i < n; i++)
#define ford(i,n,a)     for(ll i = n-1; i >= a; i--)
#define pb              push_back
#define lb              lower_bound
#define ub              upper_bound
#define pll             pair<ll,ll>
#define all(a)          (a).begin(),(a).end()
#define reset(a,x)      memset(a,x,sizeof(a))

ll mypow(ll base, ll exp) {ll res = 1; while (exp) {if (exp & 1) res = (res * base) % mod; exp >>= 1, base = (base * base) % mod;} return res;}
ll gcd(ll a, ll b)  { return b ? gcd(b, a % b) : a;            }
ll mult(ll a, ll b) { if (a < 0) {a += mod;} if (b < 0) {b += mod;} return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b)  { if (a < 0) {a += mod;} if (b < 0) {b += mod;} return (a % mod + b % mod) % mod;        }
ll sub(ll a, ll b)  { if (a < 0) {a += mod;} if (b < 0) {b += mod;} return (a % mod + mod - b % mod) % mod;  }

#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << " | ";
	err(++it, args...);
}

const ll inf = 1e18;
const int nax = 1e5 + 5;

int main()
{
	speedup_IO;

	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll n,s;
		cin>>n>>s;
		
		ll a[n+1];
		forn(i,1,n+1)
		{
			cin>>a[i];
		}
		
		ll dp[n+1][3001];
		ll pref[n+1][3001];
		reset(pref,0);
		reset(dp,0);
		
		forn(i,1,n+1)
		{
			dp[i][a[i]] = i;
		}
		
		forn(i,1,n+1)
		{
			forn(j,0,s+1)
			{
				if(j-a[i] > 0)
				{
					dp[i][j] = pref[i-1][j-a[i]];
				}
				pref[i][j] = add(pref[i-1][j],dp[i][j]);
			}	 
		}
		
		// forn(i,1,n+1)
		// {
			// forn(j,0,s+1)
			// {
				// dbg(i,j,dp[i][j]);
			// }
		// }
		
		ll ans = 0;
		forn(i,1,n+1)
		{
			ans = add(ans,mult(n-i+1,dp[i][s]));
		}
		cout<<ans;
	}

	return 0;
}
