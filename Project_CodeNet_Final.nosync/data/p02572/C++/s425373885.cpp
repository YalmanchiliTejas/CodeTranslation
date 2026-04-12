#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "Yes" : "No")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 2e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "3";

int quickPow(int x, int n) {
    if (n == 0) {
        return 1;
    }

    int t = quickPow(x, n / 2);
    (t *= t) %= mod;

    if (n % 2 == 0) {
        return t;
    }
    return ((t * x) % mod);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int n;
    cin >> n;

    int sum = 0, sumsqr = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        (sum += a) %= mod;
        (sumsqr += (a * a)) %= mod;
    }

    cout << ((((sum * sum - sumsqr + mod) % mod) * quickPow(2, mod - 2)) % mod) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
