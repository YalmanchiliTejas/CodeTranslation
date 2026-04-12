#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lint long long
#define pii pair<int, int>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) FOR(i, 0, n)
#define SZ(v) ((int)v.size())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define FILLINF(a) memset(a, 0x3f, sizeof(a))
#define POW(n) (1LL << (n))
#define POPCNT(n) (__builtin_popcount(n))
#define IN(i, a, b) ((a) <= (i) && (i) <= (b))
using namespace std;
template <typename T> inline bool CHMIN(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(begin(a), end(a)); }
template <typename T> inline void REV(T& a) { reverse(begin(a), end(a)); }
template <typename T> inline void UNI(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <typename S, typename T> inline T LB(S& v, T a) { return *lower_bound(begin(v), end(v), a); }
template <typename S, typename T> inline int LBP(S& v, T a) { return lower_bound(begin(v), end(v), a) - begin(v); }
template <typename S, typename T> inline T UB(S& v, T a) { return *upper_bound(begin(v), end(v), a); }
template <typename S, typename T> inline int UBP(S& v, T a) { return upper_bound(begin(v), end(v), a) - begin(v); }
template <typename S, typename T> ostream& operator << (ostream& os, const pair<S, T>& p) { os << p.first << " " << p.second; return os; }
template <typename S, typename T> istream& operator >> (istream& is, pair<S, T>& p) { is >> p.first >> p.second; return is; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (int i = 0; i < v.size(); ++i) { if (i) os << " "; os << v[i]; } return os; }
template <typename T> istream& operator >> (istream& is, vector<T>& v) { for(T& in : v) is >> in; return is; }
template <typename T = int> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }
template <typename T, typename V> typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) { t = v; }
template <typename T, typename V> typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) { for(auto &e : t) fill_v(e, v); }
const double PI = 3.14159265358979323846;
const double EPS = 1e-10;
const lint INF = 0x3f3f3f3f3f3f3f3f;
const lint MOD = 1000000007;

void _main() {
    int N, A, B, C, X;
    while (cin >> N >> A >> B >> C >> X, N) {
        vector<int> Y(N);
        cin >> Y;
        int f = 0, i = 0;
        while (f <= 10000) {
            if (X == Y[i]) {
                i++;
                if (i == N) break;
            }
            X = (A * X + B) % C;
            f++;
        }
        if (f > 10000) cout << -1 << endl;
        else cout << f << endl;
    }
}

signed main(signed argc, char **argv) {
    if (argc > 1) {
        if (strchr(argv[1], 'i')) freopen("input.txt", "r", stdin);
        if (strchr(argv[1], 'o')) freopen("output.txt", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
