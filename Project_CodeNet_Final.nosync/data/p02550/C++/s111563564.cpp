#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
#define forn(a, e) for (i64 a = 0; a < (i64)(e); a++)
#define forr(a, s, e) for (i64 a = s; a < (i64)(e); a++)
#define fore(e, a) for (auto& e : a)

#ifdef LOCAL
#define logv(a) {cerr << #a << " = "; fore(e, a) {cerr << e << " ";} cerr << "\n";}
#define logvp(a) {cerr << #a << " = "; fore(e, a) {cerr << "(" << e.first << ", " << e.second << ") ";} cerr << "\n";}
#define logvv(a) {cerr << #a << " = \n"; fore(r, a) { fore(e, r) {cerr << e << " ";} cerr << "\n";} }
#define logvf(a, field) {cerr << #a"."#field << " = \n"; fore(e, a) { cerr << e.field << " ";} cerr << "\n"; }
#define logvff(a, f1, f2) {cerr << #a".{"#f1 << ", "#f2 << "} = \n"; fore(e, a) { cerr << "(" << e.f1 <<", " << e.f2 << ") ";} cerr << "\n"; }
#define logs(a) cerr << #a << " = " << (a) << "\n";
#define logss(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << "\n";
#define logp(a) cerr << #a << " = " << "(" << a.first << ", " << a.second << ")" << "\n";
#define cond(pred, stmt) if (pred) { stmt }
#else
#define logv(a)
#define logvp(a)
#define logvv(a)
#define logvf(a, field)
#define logvff(a, f1, f2)
#define logs(a)
#define logss(a, b)
#define logp(a)
#define cond(pred, stmt)
#endif

using iip = pair<int, int>;
using llp = pair<i64, i64>;
using ivec = vector<int>;
using llvec = vector<i64>;
using svec = vector<string>;
template<typename T> using vec = vector<T>;

template<typename T, typename Dim>
auto make_vec(T value, Dim dim) { return vector<T>(dim, value); }
template<typename T, typename Dim1, typename... Dim>
auto make_vec(T value, Dim1 dim1, Dim... dims) { return make_vec(make_vec(value, dims...), dim1); }

template<typename T>
bool uax(T& v, const T& newv) { if (v < newv) { v = newv; return true; } else return false; }
template<typename T>
bool uin(T& v, const T& newv) { if (v > newv) { v = newv; return true; } else return false; }

template<typename T>
istream& operator>>(istream& is, vector<T>& c) { for (auto& e : c) is >> e; return is; }
template<typename T, size_t N>
istream& operator>>(istream& is, array<T, N>& c) { for (auto& e : c) is >> e; return is; }

template<typename ...T>
istream& read(T&... args) { return (cin >> ... >> args); }

static mt19937 rande(123123);
template<typename T>
T rand_int(T from, T to) { uniform_int_distribution<T> distr(from, to); return distr(rande); }

// const i64 INF = 1e18;
const int INF = 2e9;
const i64 M = 998244353;
const int MXB = 20;
using bin = bitset<MXB + 1>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    rande.seed(chrono::steady_clock::now().time_since_epoch().count());

    i64 n, x, m;
    while (read(n, x, m)) {
        llvec a = {x};
        map<i64, int> pos;
        pos[x] = 0;
        i64 pp = -1;
        forn(i, m + 1) {
            i64 na = a.back() * a.back() % m;
            if (pos.count(na)) {
                pp = pos[na];
                break;
            }
            if (na == 0) {
                break;
            }
            pos[na] = a.size();
            a.push_back(na);
        }

        // logv(a);
        logs(a.size());

        llvec sa(a.size() + 1);
        forn(i, a.size()) {
            sa[i + 1] = sa[i] + a[i];
        }

        if (pp == -1) {
            uin<i64>(n, a.size());
            cout << sa[n] << endl;
        } else {
            if (n <= a.size()) {
                cout << sa[n] << endl;
            } else {
                logs(pp);
                i64 ans = sa[pp];
                n -= pp;
                i64 r = n % (a.size() - pp);
                ans += (n / (a.size() - pp)) * (sa.back() - sa[pp]);
                ans += sa[r + pp] - sa[pp];
                cout << ans << endl;
            }
        }
    }
}