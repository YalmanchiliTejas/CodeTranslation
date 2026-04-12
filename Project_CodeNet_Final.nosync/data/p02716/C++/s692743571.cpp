#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1ll << 60;
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
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
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
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int, int>>
#define vvp vector<vector<pair<int, int>>>
#define pi pair<int, int>
//#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
#define asn ans
bool dbg = false;

int N, A[202020];
int dp[202020][4];

void solve() {
    Fill(dp, -INF);

    FOR (i, 0, N) {
        if (i == 0) {
            dp[i][0] = A[i];
            continue;
        }
        if (i == 1) {
            dp[i][1] = A[i];
            continue;
        }
        if (i == 2)
            dp[i][2] = A[i];
        if (i % 2 == 0) {
            dp[i][0] = dp[i - 2][0] + A[i];
            if (i > 2) {
                dp[i][2] = max({dp[i - 2][2], dp[i - 3][1], dp[i - 4][0]}) + A[i];
            }
        } else {
            dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + A[i];
        }
    }
    int ans = -INF;
    if (N % 2 == 0) {
        ans = max(dp[N - 1][1], dp[N - 2][0]);
    } else {
        chmax(ans, dp[N - 1][2]);
        chmax(ans, dp[N - 2][1]);
        if (N - 3 >= 0)
            chmax(ans, dp[N - 3][0]);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    FOR (N)
        cin >> A[i];

    solve();
    return 0;
}
