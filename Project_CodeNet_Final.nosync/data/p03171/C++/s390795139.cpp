#include <bits/stdc++.h> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define nl '\n'
 
#define y1 aza_ibagaliev
 
#define f first
#define s second
	
#define ed end()
#define bg begin()
#define rbg rbegin()
 
#define rv reverse
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ppf pop_front
 
#define sz size()
#define all(x) x.bg, x.ed
 
#define pll pair < ll, ll >
#define pii pair < int, int >
 
#define sqr(x) ((x) * 1ll * (x))
#define sqrd(x) ((x) * 1.0 * (x))
 
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define rnl cout << "----------------------------------------" << nl
 
#define bit __builtin_popcount
 
inline ll bip(ll x, ll n, ll mod){ll res=1;while(n){if(n & 1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}
        	
const int ppr = 257;
const ll INF = 2e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int N = 1e5 + 123;
const ld pi = 3.1741592653589793238462643;
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, a[3004];
ll dp[3004][3004], p[3004];
bool u[3004][3004];

ll rec(int l, int r) {
	if(u[l][r]) return dp[l][r];
	u[l][r] = 1;
	if(l == r) return dp[l][r] = a[l];
	ll s = p[r] - p[l - 1];
	return dp[l][r] = max(s - rec(l + 1, r), s - rec(l, r - 1));
}

main() {             	
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

//	srand(time(NULL));

	scanf("%d", &n);
  
    ll sum=0;

    for(int i = 1; i <= n; i++)
    	scanf("%d", &a[i]), p[i] = p[i - 1] + a[i];

	cout << 2 * rec(1, n) - p[n];

    return 0;                                        
}