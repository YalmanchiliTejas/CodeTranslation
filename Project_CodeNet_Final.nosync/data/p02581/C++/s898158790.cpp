#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int x) { return (x > 0) - (x < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

signed main() {
    int N;
    cin >> N;
    vint A(3 * N);
    rep(i, 3 * N) { cin >> A[i], A[i]--; }
    int bias = 0, ans = 0;
    vvint dp(N, vint(N, -1));
    vint rmax(N, -1);
    dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
    rmax[A[0]] = rmax[A[1]] = 0;
    rep(i, N - 1) {
        vint a = {A[3 * i + 2], A[3 * i + 3], A[3 * i + 4]};
        if (a[0] == a[1] && a[1] == a[2]) {
            bias++;
            continue;
        }
        vector<tuple<int, int, int>> query;
        rep(j, 3) {
            vint aa;
            rep(k, 3) { if (j != k) { aa.emplace_back(a[k]); }}
            query.emplace_back(aa[0], aa[1], ans);
            if (dp[a[j]][a[j]] >= 0) { query.emplace_back(aa[0], aa[1], dp[a[j]][a[j]] + 1); }
            rep(k, N) {
                query.emplace_back(k, a[j], rmax[k]);
                if (aa[0] == aa[1] && dp[k][aa[0]] >= 0) { query.emplace_back(k, a[j], dp[k][aa[0]] + 1); }
            }
        }
        rep(j, query.size()) {
            auto[x, y, v]=query[j];
            chmax(dp[x][y], v), chmax(dp[y][x], v);
            chmax(rmax[x], v), chmax(rmax[y], v);
            chmax(ans, v);
        }
    }
    chmax(ans, dp[A[3 * N - 1]][A[3 * N - 1]] + 1);
    ans += bias;
    cout << ans << endl;
}
