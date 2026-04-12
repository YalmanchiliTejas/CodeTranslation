#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl '\n'
//#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define BIT(n) (1LL << (n))
#define TOUPPER(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define TOLOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define FILLZERO(s, n)                      \
    do {                                    \
        ostringstream os;                   \
        os << setw(n) << setfill('0') << s; \
        s = os.str();                       \
    } while (0);
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
#define INIT                               \
    std::cin.tie(nullptr);                 \
    std::ios_base::sync_with_stdio(false); \
    cout << std::fixed << std::setprecision(10);

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi = pair<int, int>;
template <typename T>
using Pq = priority_queue<T>;
template <typename T>
using pQ = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
vector<T> make_vec(size_t a, T n) { return vector<T>(a, n); }
template <typename T, typename... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

int main() {
    INIT;
    cin >> N;
    vi a(N);
    cin >> a;
    vector<map<int, ll[2]>> dp(N + 1);
    REP(i, N + 1) {
        FOR(jj, -10, 10) {
            int j = i / 2 + jj;
            dp[i][j][0] = -1e18;
            dp[i][j][1] = -1e18;
        }
    }
    dp[0][0][0] = 0;
    REP(i, N) {
        FOR(jj, -5, 5) {
            int j = i / 2 + jj;
            chmax(dp[i + 1][j + 1][1], dp[i][j][0] + a[i]);
            chmax(dp[i + 1][j][0], dp[i][j][0]);
            chmax(dp[i + 1][j][0], dp[i][j][1]);
            dump(dp[i + 1][j][1]);
        }
    }
    cout << max(dp[N][N / 2][0], dp[N][N / 2][1]) << endl;
}