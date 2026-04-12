#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(n) FOR(O, 1, (n))
#define pb push_back
#define f first
#define s second
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<piii> viii;

const int MAXN = 500100, MAXK = 30;
const ll MOD = 998244353;
const ll INF = 1e15;
const ld PI = asin(1) * 2;

void setIO () {
    FAST_IO;
}

void setIO (string s) {
    setIO();
 	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n;
ll a[MAXN];
ll dp[MAXN][5];
bool found[MAXN][5];

int main() {
	setIO();

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 0, n) FOR(j, 0, 4) dp[i][j] = -INF;
    FOR(i, 0, n) FOR(j, 0, 4) found[i][j] = false;

    FOR(i, 1, n) FOR(j, 0, 2) {

        ll mx = -INF;

        FOR(k, 0, j) {
            if (i > k+2 && found[i-2-k][j-k]) {
                mx = max(mx, dp[i-2-k][j-k]);
                found[i][j] = true;
            }
        }
//cout << " mx=" << mx << " =inf=" << (-INF) << endl;
        if (mx > (-INF)) dp[i][j] = mx;
        else if (i == j+1) {
            mx = 0ll;
            found[i][j] = true;
        }
//cout << " mx=" << mx << " =inf=" << (-INF) << endl;

        dp[i][j] = mx;

        if (found[i][j])dp[i][j] += a[i];
        else dp[i][j] = -INF;

        //cout << " i=" << i << " j=" << j << " dp(i,j)=" << dp[i][j] << endl;
    }

    ll ans = -INF;
    if (n%2 == 0) {
        ans = max(ans, dp[n-1][0]);
        ans = max(ans, dp[n][1]);
    } else {
        ans = max(ans, dp[n-2][0]);
        ans = max(ans, dp[n-1][1]);
        ans = max(ans, dp[n][2]);
    }

    cout << ans;

	return 0;
}


