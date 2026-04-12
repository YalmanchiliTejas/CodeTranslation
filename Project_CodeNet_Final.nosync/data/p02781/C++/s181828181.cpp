#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1e10;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define P pair<int, int>
#define V vector<int>
//#define S set<int>
#define itn int
bool dbg = false;

int K;
string N;

itn dp[111][3][10];


void solve() {
    FOR(i, 0, (int)N.size()) {
        N[i] -= '0';
    }
    int Z = N.size();

    int n = N[0];
    dp[0][0][0] = 1;
    dp[0][0][1] = n - 1;
    dp[0][1][1] = 1;
    FOR(i, 1, Z) {
        FOR(k, 0, 5) {
            dp[i][0][k] += dp[i - 1][0][k];
            if (k > 0)
                dp[i][0][k] += dp[i - 1][0][k - 1] * 9;
            int n = N[i];
            if (n != 0) {
                if (k > 0)
                    dp[i][1][k] += dp[i - 1][1][k - 1];
                if (k > 0)
                    dp[i][0][k] += dp[i - 1][1][k - 1] * (n - 1);
                dp[i][0][k] += dp[i - 1][1][k];
            } else {
                dp[i][1][k] += dp[i - 1][1][k];
            }
        }
    }
    /*
    FOR(i, 0, Z) {
        FOR(k, 0, K + 1) {
            //cerr << i << " " << k << endl;
            //cerr << dp[i][0][k] << " " << dp[i][1][k] << endl
            //<< endl;
        }
    }
    */
    cout << dp[Z - 1][0][K] + dp[Z - 1][1][K] << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> K;

    solve();
    return 0;
}
