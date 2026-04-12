#include <bits/stdc++.h>

using namespace std;

#define forn(a, e) for (int a = 0; a < (int)(e); a++)
#define forr(a, s, e) for (int a = s; a < (int)(e); a++)
#define fore(e, a) for (auto& e : a)

#ifdef LOCAL
#define logv(a) {cerr << #a << " = "; fore(e, a) {cerr << e << " ";} cerr << "\n";}
#define logvp(a) {cerr << #a << " = "; fore(e, a) {cerr << "(" << e.first << ", " << e.second << ") ";} cerr << "\n";}
#define logvv(a) {cerr << #a << " = \n"; fore(r, a) { fore(e, r) {cerr << e << " ";} cerr << "\n";} }
#define logvf(a, field) {cerr << #a"."#field << " = \n"; fore(e, a) { cerr << e.field << " ";} cerr << "\n"; }
#define logs(a) cerr << #a << " = " << (a) << "\n";
#define logss(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << "\n";
#define logp(a) cerr << #a << " = " << "(" << a.first << ", " << a.second << ")" << "\n";
#define cond(pred, stmt) if (pred) { stmt }
#else
#define logv(a)
#define logvp(a)
#define logvv(a)
#define logvf(a, field)
#define logs(a)
#define logss(a, b)
#define logp(a)
#define cond(pred, stmt)
#endif

using i64 = long long;
using iip = pair<int, int>;
using ivec = vector<int>;
using llvec = vector<i64>;
using svec = vector<string>;

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

// template<typename ...T>
// istream& read(T&... args) { return (cin >> ... >> args); }

static mt19937 rande(123123);
template<typename T>
T rand_int(T from, T to) { uniform_int_distribution<T> distr(from, to); return distr(rande); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i64 n, m, k;
    while (cin >> n >> m >> k) {
        constexpr int M = 1e9 + 7;

        auto s2 = make_vec(0ll, n, m);
        auto c2 = make_vec(0ll, n, m);
        auto cr = [&](i64 i) {
            return (i * (i + 1) / 2 + (m - i) * (m - i - 1) / 2) % M;
        };

        i64 sum2 = 0;
        i64 cc2 = 0;

        i64 s0 = 0;
        forn(i, m) {
            s2[0][i] = cr(i);
            c2[0][i] = (i + m - i) % M;
            sum2 += s2[0][i];
            sum2 %= M;
            cc2 += c2[0][i];
            cc2 %= M;
            s0 += s2[0][i];
            s0 %= M;
        }

        forr(i, 1, n) forr(j, 0, m) {
            s2[i][j] += (c2[i - 1][j] + s2[i - 1][j] + cr(j)) % M;
            c2[i][j] = (c2[i - 1][j] + j + m - j) % M;    
            sum2 += s2[i][j];
            cc2 += c2[i][j];
            sum2 %= M;
            cc2 %= M;
        }

        logvv(s2);
        logvv(c2);
        logss(sum2, cc2);

        function<i64(i64, i64)> bpow = [&](i64 x, i64 p) -> i64 {
            if (x == 1) {
                return 1;
            }
            if (p == 0) {
                return 1;
            }

            i64 res = bpow(x, p / 2);
            res *= res;
            res %= M;
            if (p % 2 == 1) {
                res *= x;
                res %= M;
            }
            return res;
        };

        s0 *= bpow(2, M - 2);
        s0 %= M;

        forn(i, n) {
            sum2 -= s0;
            sum2 += M;
            sum2 %= M;
        }
        logs((2 * bpow(2, M - 2)) % M);

        i64 ss2 = 0;
        forn(i, n) forn(j, m) forn(x, n) forn(y, m) {
            if (i != x || j != y) {
                ss2 += abs(i - x) + abs(j - y);
            }
        }
        ss2 /= 2;

        i64 a = 1;
        i64 b = 1;
        forn(i, k - 2) {
            a *= (n * m - 2 - i);
            a %= M;
            b *= i + 1;
            b %= M;
        }

        logss(sum2, ss2);

        logss(a, b);

        i64 cc = (a * bpow(b, M - 2)) % M;
        logs(cc);
        i64 ans = (cc * sum2) % M;
        cout << ans << endl;
    }
}
