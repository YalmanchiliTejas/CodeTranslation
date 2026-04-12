// Date: 2020-03-13

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 3000 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n;
LL dp[N][N], a[N];

int main() {
    FIO;
    cin >> n;
    rep(i, 1, n) rep(j, 1, n) dp[i][j] = -INF;
    rep(i, 1, n) cin >> a[i], dp[i][i] = a[i];
    rep(len, 1, n) {
        rep(i, 1, n-len) {
            int j = i+len;
            chkmax(dp[i][j], a[i] - dp[i+1][j]);
            chkmax(dp[i][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[1][n];

    return 0;
}