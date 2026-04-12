#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n-1); i >= 0; i--)
#define all(v) (v).begin(),(v).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a/gcd(a,b)*b; }
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const ll MOD = 998244353;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(s+1, vector<ll>(3)));
	// dp[0][0][0] = 1;
    rep(i,n+1) dp[i][0][0] = 1;
	rep(i,n) rep(j,s+1) {
        // a[i]を選ばない場合
        // (dp[i+1][j][0] += dp[i][j][0]) %= MOD;
        (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
        (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD;
		if(j + a[i] <= s) { // a[i]を選ぶ場合
            (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
		}
	}
	cout << dp[n][s][2] << endl;
	return 0;
}
