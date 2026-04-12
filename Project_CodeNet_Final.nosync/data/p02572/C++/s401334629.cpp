/**
 *	author: tanishq_code_c
**/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



void __print(int x) {cerr << x;}; void __print(long x) {cerr << x;}; void __print(long long x) {cerr << x;}; void __print(unsigned x) {cerr << x;}; void __print(unsigned long x) {cerr << x;}; void __print(unsigned long long x) {cerr << x;}; void __print(float x) {cerr << x;}; void __print(double x) {cerr << x;}; void __print(long double x) {cerr << x;}; void __print(char x) {cerr << '\'' << x << '\'';}; void __print(const char *x) {cerr << '\"' << x << '\"';}; void __print(const string &x) {cerr << '\"' << x << '\"';}; void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif


#define int             							long long
#define setbits(x)     							    __builtin_popcountll(x)
#define zerobits(x)     							__builtin_ctzll(x)
#define mod             							1000000007
#define inf            							    1e18
#define endl            							'\n'
#define pb              							push_back
#define all(x)          							x.begin(),x.end()
#define ff              							first
#define ss              							second
#define rep(i,n)                                  	for(int i = 0; i < n; i++)
#define set(n)                                      fixed << setprecision(n)

int powmod(int a, int b) {int res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
int fast_pow(int a, int b) {if (b == 1) return a; if (b == 0) return 1; int x = fast_pow(a, b / 2); x *= x; if (b & 1) x *= a; return x;}

void t_c_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif*/
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int pre[n];
	pre[0] = arr[0] % mod;
	for (int i = 1; i < n; i++) {
		pre[i] = (pre[i - 1] % mod + arr[i] % mod) % mod;
		pre[i] %= mod;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int elem = (((pre[n - 1] - pre[i]) % mod) + mod) % mod;
		ans += (arr[i] % mod * elem % mod) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int32_t main()
{
	t_c_c();
	return 0;
}
