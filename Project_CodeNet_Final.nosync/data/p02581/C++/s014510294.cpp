#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl '\n'
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
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

signed main() {
    INIT;
    cin >> N;
    vi a(3 * N);
    cin >> a;
    auto dp = make_vec<int>(N + 1, N + 1, -10000);
    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    int mx = 0;
    vi vmx(N + 1, -10000);
    vmx[a[0]] = 0;
    vmx[a[1]] = 0;
    REP(i, N - 1) {
        int ind = 3 * i + 2;
        int p = a[ind], q = a[ind + 1], r = a[ind + 2];
        if (p == q && q == r) {
            ans++;
            continue;
        }

        if (p == q) {
            swap(q, r);
        } else if (q == r) {
            swap(p, q);
        }
        int pp = dp[p][p];
        int qq = dp[q][q];
        int rr = dp[r][r];
        vi pk = dp[p];
        vi kp(N + 1);
        REP(k, N + 1)
        kp[k] = dp[k][p];

        dump(dp);
        chmax(dp[p][q], mx);
        chmax(dp[q][r], mx);
        chmax(dp[r][p], mx);
        REP(k, N + 1) {
            chmax(dp[k][p], vmx[k]);
            chmax(dp[k][q], vmx[k]);
            chmax(dp[k][r], vmx[k]);
        }
        REP(k, N + 1) {
            chmax(vmx[k], dp[k][p]);
            chmax(vmx[p], dp[k][p]);
            chmax(vmx[k], dp[k][q]);
            chmax(vmx[q], dp[k][q]);
            chmax(vmx[k], dp[k][r]);
            chmax(vmx[r], dp[k][r]);
        }
        if (p == q || q == r || p == r) {
            dump(dp, p, q, r);
            REP(k, N + 1) {
                chmax(dp[k][q], pk[k] + 1);
                chmax(dp[k][q], kp[k] + 1);

                chmax(vmx[k], dp[k][q]);
                chmax(vmx[q], dp[k][q]);
            }
        }
        chmax(dp[p][q], rr + 1);
        chmax(dp[q][r], pp + 1);
        chmax(dp[r][p], qq + 1);
        chmax(vmx[p], dp[p][q]);
        chmax(vmx[q], dp[p][q]);

        chmax(vmx[q], dp[q][r]);
        chmax(vmx[r], dp[q][r]);

        chmax(vmx[r], dp[r][p]);
        chmax(vmx[p], dp[r][p]);

        REP(k, N + 1) {
            chmax(mx, vmx[k]);
        }
    }
    dump(dp, ans);
    int res = 0;
    dp[a[3 * N - 1]][a[3 * N - 1]]++;
    REP(i, N + 1) {
        REP(j, N + 1) {
            chmax(res, dp[i][j]);
        }
    }
    cout << res + ans << endl;
}