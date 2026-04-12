#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
ll MOD = 1e9 + 7;

const int MAXN = 3e3 + 5;

ll dp[MAXN][MAXN];
ll c[MAXN][MAXN];

void solve(){
	int n;
	cin >> n >> MOD;
	c[0][0] = 1ll;
	dp[0][0] = 1ll;
	REPN(i, 1, n) {
		c[i][0] = 1ll;
		dp[i][0] = 1ll;
		REPN(j, 1, i) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + j * dp[i - 1][j]) % MOD;
		}
	}
	ll ans = 0ll;
	REPN(i, 0, n) {
		ll mul = c[n][i];
		if (i % 2 == 1) {
			mul = MOD - mul;
		}
		ll st2 = 2ll;
		ll st2_ni = 1ll;
		REP(j, 0, n - i) {
			st2 = (st2 * st2) % MOD;
			st2_ni = (st2_ni * 2ll) % MOD;
		}
		ll mul2 = 0ll;
		ll st_st2_ni = 1ll;
		REPN(j, 0, i) {
			ll add = (dp[i][j] * st_st2_ni) % MOD;
			mul2 = (mul2 + add) % MOD;
			st_st2_ni = (st_st2_ni * st2_ni) % MOD;
		}
		mul2 = (mul2 * st2) % MOD;
		ans = (ans + mul * mul2) % MOD;
	}
	cout << ans << endl;
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
