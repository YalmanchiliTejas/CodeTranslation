#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;
 
typedef long long ll;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
 
#define read(a) int a; cin >> a;
#define readb(a, b) int a, b; cin >> a >> b;
#define readc(a, b, c) int a, b, c; cin >> a >> b >> c;
#define readarr(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
 
#define print(a) cout << a << endl;
#define printarr(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printv(v) for (int i: v) cout << i << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define vvi vector <vi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll inf = 1e18;
const ll mod = 998244353;
const ll N = 2e4 + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	readb(n, s);
	readarr(a, n);
	
	int dp[3001] = {}, ans = 0;
	FOR (i, 1, n)
	{
	    if (s - a[i] > 0) ans = (ans + dp[s - a[i]] * (n - i + 1)) % mod;
	    else if (s == a[i]) ans = (ans + i*(n - i + 1)) % mod;
	    
	    FORD (j, s, a[i])
	        dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	        
	    dp[a[i]] = (dp[a[i]] + i) % mod;
	}
	
	cout << ans;
}

















