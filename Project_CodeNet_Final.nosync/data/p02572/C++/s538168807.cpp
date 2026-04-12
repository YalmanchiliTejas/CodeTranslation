#include <bits/stdc++.h>

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;

#define sqr(a) ((a)*(a))
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define nrof(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define rep(i, k, n) for(int i = (int)k; i < (int)n; ++i)
#define per(i, k, n) for(int i = (int)k - 1; i >= (int)n; --i)
#define x first
#define y second
#define mp make_pair
#define sz(a) (int)(a.size())
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e6 + 9;
const int M = 2e3 + 9;
const int INFINT = 1e9 + 9;
const ll INFLL = 1e18 + 9;
const ll MOD = (ll) (1000000007);

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    ll sum = 0;
    forn(i, n) sum += a[i];

    ll ans = 0;
    forn(i, n) {
        sum -= a[i];
        ans = (ans + (sum % MOD) * (a[i] % MOD)) % MOD;
    }
    cout << ans % MOD << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
