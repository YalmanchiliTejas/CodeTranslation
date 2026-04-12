#include <bits/stdc++.h>
     
using namespace std;
     
#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())
#define	endl			'\n'
     
typedef long long		ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>		vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>		vpii;
     
const int MX = 3005;

ll dp[MX][MX][2];
const ll BIG = 10000000000LL;

ll solve(int p, int l, int r, vi &A)
{
	if (l > r) return 0;
	if (dp[l][r][p] != BIG) return dp[l][r][p];
	if (p&1) {
		ll res1 = -A[l]+solve((p+1)&1,l+1,r,A);
		ll res2 = -A[r]+solve((p+1)&1,l,r-1,A);
		return dp[l][r][p] = min(res1,res2);
	} else {
		ll res1 = A[l]+solve((p+1)&1,l+1,r,A);
		ll res2 = A[r]+solve((p+1)&1,l,r-1,A);
		return dp[l][r][p] = max(res1,res2);
	}
}

int main(int argc, char *argv[])
{
#ifdef	HTRINH_UNIT_TEST
	freopen(argv[1],"r",stdin);
	ifstream cin(argv[1]);
#endif
#if 0
	ofstream cout(argv[2]);
#endif
	ios :: sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vi a(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) FOR(j,0,n) FOR(k,0,2) dp[i][j][k] = BIG;
	ll x = solve(0,0,n-1,a);
	cout << x << endl;
    return 0;
}
