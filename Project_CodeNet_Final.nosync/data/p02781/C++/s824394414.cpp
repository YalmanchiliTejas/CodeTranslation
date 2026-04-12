#include <bits/stdc++.h>

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1100;
char s[maxn];
i64 k, dp[maxn][4][2]; //0: ==  1: <
// i j k -> 前i位有j个非0的数

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin);
#endif

	cin >> (s + 1);
	int len = strlen(s + 1);
	cin >> k;
	ms(dp, 0);
	dp[0][0][0] = 1;
	for (int i = 1; i <= len; ++i) {
        dp[i][0][1] = 1;
	}
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (s[i] == '0') {
                dp[i][j][1] = dp[i - 1][j - 1][1] * 9 + dp[i - 1][j][1];
                dp[i][j][0] = dp[i - 1][j][0];
            } else {
                int num = s[i] - '0';
                dp[i][j][1] = dp[i - 1][j - 1][1] * 9 + dp[i - 1][j - 1][0] * (num - 1) + dp[i - 1][j][0] + dp[i - 1][j][1];
                dp[i][j][0] = dp[i - 1][j - 1][0];
            }
        }
    }
//    cerr << dp[1][1][1] << " " << dp[1][1][0] << '\n';
    cout << (dp[len][k][0] + dp[len][k][1]) << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
