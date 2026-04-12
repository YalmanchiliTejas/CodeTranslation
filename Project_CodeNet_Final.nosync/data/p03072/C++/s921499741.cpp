#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
// io
#define get(i) scanf("%d", &i)
#define flush fflush(stdin)

// manipulations
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i >= 0; i--)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define sz(x) int((x).size())
#define fi first
#define se second

// built-in
#define bitcount __builtin_popcount
#define gcd __gcd

// short
#define pb push_back
#define fill(arr, a) memset(arr, a, sizeof(arr))
#define mp(a,b) make_pair(a,b)

// useful bits
#define IN(i,l,r) (i >= l && i <= r);
#define relax(a,b) a = max(a,b);
#define relaxi(a,b) a = min(a,b);

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef long double ld;

ll modpow(ll a, ll b, ll mod = (ll) (1e9 + 7)) 
{if (!b) return 1; a %= mod; return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;}

// for rand
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// use uniform_int_distribution<int>(0, i)(rng)



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
//	freopen("output.txt", "w" , stdout);
	/* freopen("in.txt" , "r" , stdin); */
	/* clock_t start = clock(); */
	#endif
	int n , h;
	cin >> n;
	int mx = -1;
	int ans = 0;
	while(n-- > 0){
		cin >> h;
		if( h >= mx )
			ans++, mx = h;
	}
	cout << ans << endl;

	#ifndef ONLINE_JUDGE
	/* cout << setprecision(12) << ld(clock()-start) / CLOCKS_PER_SEC << endl; */
	#endif
	return 0;
}

