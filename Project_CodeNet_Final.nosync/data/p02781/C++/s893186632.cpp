#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
const ll mod = 1e18 + 7;

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
ll mult(ll a, ll b) { return ((a ) * (b ));    }
ll add(ll a, ll b)  { return (a  + b ) ;        }
ll sub(ll a, ll b)  { return (a  - b) ;  }

const ll inf = 1e18;
const int nax = 110;

ll n,k;
string s;
ll dp[nax][4][2];

ll solve(ll idx,ll allowed,ll rqd)
{
	if(rqd<0)
		return 0;

	if(idx>=n)
	{
		if(rqd == 0)
			return 1;
		else
			return 0;
	}

	if(dp[idx][rqd][allowed]!=-1)
		return dp[idx][rqd][allowed];

	ll ans = 0;
	if(allowed == 0)
	{
		if((s[idx]-'0'-1)>0)
		{
			ans = (s[idx]-'0'-1)*solve(idx+1,1,rqd-1);
		}

		if(s[idx]!='0')
		{
			ans = ans + solve(idx+1,0,rqd-1);
          	ans = ans + solve(idx+1,1,rqd);
		}
      	else
        {
          	ans = ans + solve(idx+1,0,rqd);
        }
		
	}

	else
	{
		ans = 9*solve(idx+1,1,rqd-1)+ solve(idx+1,1,rqd);
	}

	dp[idx][rqd][allowed] = ans;
	return ans;
}

int main()
{
	speedup_IO;
	
	cin>>s>>k;
	n = s.length();

	ll ans = 0;

	forn(i,0,nax)
	{
		forn(j,0,4)
		{
			forn(k,0,2)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	ans = solve(0,0,k);
	cout<<ans;

	return 0;
}
