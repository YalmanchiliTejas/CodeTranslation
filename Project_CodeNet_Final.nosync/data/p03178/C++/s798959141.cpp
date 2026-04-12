#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define out(x) #x << " = " << x
#define yn(x) ((x) ? "YES" : "NO")
using namespace std;
typedef pair <int, int> ii;

const int siz = 1e4 + 10;
const int SIZ = 1e2 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;

string k;
int d;
int f[siz][2][SIZ];

int dp(int pos, int lim, int sum) {
    if (pos == sz(k)) {
        return (sum == 0);
    }

    int &res = f[pos][lim][sum];
    if (res != -1) {
        return res;
    }

    res = 0;
    int n = ((lim) ? k[pos] - '0' : 9);
    for (int i = 0; i <= n; i++) {
        (res += dp(pos + 1, lim & (i == n), (sum + i) % d)) %= mod;
    }

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen ("IN_5.INP", "r", stdin);
//    freopen ("OUT_5.OUT", "w", stdout);

    cin >> k >> d;

    memset(f, -1, sizeof(f));
    cout << (dp(0, 1, 0) - 1 + mod) % mod;

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms";

    return 0;
}
