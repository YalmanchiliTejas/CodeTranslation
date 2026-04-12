#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define foru(i, n) for(int i = 1; i <= n; i++)
#define foru0(i, n) for(int i = 0; i < n; i++)
#define ford(i, n) for(int i = n; i >= 1; i--)
#define ford0(i, n) for(int i = n - 1; i >= 0; i--)
#define fors(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<pll> v2l;
typedef pair<char, int> pci;
typedef vector<pci> vci;

const int N = 1e6 + 1;
const int NN = 1e3 + 1;
const ll MOD = 1e9 + 7;
const ll oo = 1e18 + 7;

void solve() {
    int n;
    cin >> n;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<long long> > dp(n + 2, vector<long long>(n + 2));
    for (int i = n; i; i--) {
        for (int j = i; j <= n; j++) {
            int rem = (n - j) + (i - 1);
            if (rem % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n];
}

int main() {
    #ifdef DEBUG
        freopen("solve.inp", "r", stdin);
        freopen("solve.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    solve();
    cerr << "Time elapsed: " << 1.0 * clock() << " ms.\n";
}
