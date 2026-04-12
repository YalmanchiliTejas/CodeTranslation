#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
using namespace std;
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb(X) push_back(X)
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
typedef long long ll;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int, int> pii;
const ll MOD = 998244353;
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


const int INF = 1e9 + 7;
int _;
int n, k;
ll ans;

int main() {
	INIT
	cin >> n >> k;
	VI A(n);
	vector<vector<ll>> dp(n + 1, vector<ll>(3030));
	rep (i, 0, n) {
		cin >> A[i];
	}
	rep (i, 0, n) {
		dp[i + 1] = dp[i];
		(dp[i + 1][A[i]] += i + 1) %= MOD;
		for (int j = 0; j + A[i] <= k; ++j) {
			(dp[i + 1][j + A[i]] += dp[i][j]) %= MOD;
		}
		(ans += dp[i + 1][k]) %= MOD;
	}
	cout << ans;
	return 0;
}