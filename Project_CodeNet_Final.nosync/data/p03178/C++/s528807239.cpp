// Date: 2020-03-16

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
const int N = 1e4 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL dp[N][100];
int a[N], D;
string s;
LL dfs(int pos, bool lim, int sum) {
    if(pos == -1) return sum % D == 0;
    if(dp[pos][sum] != -1 && !lim) return dp[pos][sum];
    int up = lim ? a[pos] : 9;
    LL ans = 0;
    rep(i, 0, up) {
        ans = (ans + dfs(pos-1, lim && i == up, (sum + i) % D)) % mod;
    }
    if(!lim) dp[pos][sum] = ans;
    return ans;
}

int main() {
    FIO;
    cin >> s >> D;
    int pos = 0;
    for(int i = s.size()-1; i >= 0; --i) a[pos++] = s[i]-'0';
    mem(dp, -1);
    LL ans = (dfs(pos-1, 1, 0) - 1 + mod) % mod;
    cout << ans;

    return 0;
}