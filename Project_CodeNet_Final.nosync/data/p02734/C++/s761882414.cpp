#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 998244353
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int main() {

	long long n, s; cin >> n >> s;
	vector<long long> a(n + 1, 0); for (long long i = 1; i <= n; i++) cin >> a[i];

	vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, 0)); //dp[i][j]=no. of subsequences ending at i, that can make 'j'

	if (a[1] <= s) dp[1][a[1]] = 1;
	for (long long i = 0; i <= n; i++) dp[i][0] = 1;
	dp[1][0] = 2;

	for (long long i = 2; i <= n; i++) {
		for (long long j = a[i]; j <= s; j++) dp[i][j] = dp[i - 1][j - a[i]];
		for (long long j = 0; j <= s; j++) dp[i][j] = ((dp[i][j] % MOD) +  (dp[i - 1][j] % MOD)) % MOD;
	}
	debug(dp);
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans = ((ans % MOD) +  (((dp[i][s] - dp[i - 1][s] + MOD) % MOD) * ((n - i + 1) % MOD)) % MOD) % MOD;
	}

	cout << ans;
	return 0;
}