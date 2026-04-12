#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 1; i <= (n); ++i)
#define repd(i, n) for (int i = (n - 1); i >= 0; --i)
#define repds(i, n) for (int i = (n); i > 0; --i)
#define loop(i, x, n) for (int i = (x); i < (n); ++i)
#define loops(i, x, n) for (int i = (x); i <= (n); ++i)
#define loopd(i, x, n) for (int i = (x); i > (n); --i)
#define loopds(i, x, n) for (int i = (x); i >= (n); --i)
#define itrep(i, a) for (auto i = begin(a); i != end(a); ++i)
#define itrepd(i, a) for (auto i = rbegin(a); i != rend(a); ++i)
#define each(i, x) for (auto &i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <class T>
using priority_queuel = priority_queue<T, vector<T>, greater<T>>;
constexpr ll inf = static_cast<ll>(1e18);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e18;
constexpr double eps = 1e-9;
ll mod = static_cast<ll>(1e9 + 7);
template <class T>
constexpr int sz(const T &a) { return (int)a.size(); }
template <class T>
constexpr T pow2(const T a) { return a * a; }
template <class T, class... Args>
constexpr void mins(T &a, Args... args) { a = min<T>({a, args...}); }
template <class T, class... Args>
constexpr void maxs(T &a, Args... args) { a = max<T>({a, args...}); }
template <class A, int N, class T>
void fillArray(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }

int n;
int ta[505], tb[505];
ull va[505], vb[505], ans[505][505];
bool res[505][505];
int cnt[505];
void transpose() {
    rep(i, n) {
        rep(j, i) swap(res[i][j], res[j][i]);
        swap(va[i], vb[i]);
        swap(ta[i], tb[i]);
    }
}
void f2(ull pos) {
    fillArray(cnt, 0);
    rep(j, n) {
        if (!tb[j]) {
            cnt[j] = n - 1;
            rep(i, n) cnt[j] -= res[i][j];
        }
    }
    rep(i, n) {
        if (ta[i] && (((va[i]) >> pos) & 1ULL)) {
            bool ok = false;
            rep(j, n) ok |= res[i][j];
            if (ok) continue;
            rep(j, n) {
                if (cnt[j] > 0) {
                    --cnt[j];
                    res[i][j] = 1;
                    break;
                }
            }
        }
    }
}
void f(ull pos) {
    fillArray(res, false);
    rep(i, n) {
        if (!ta[i] && (((va[i]) >> pos) & 1ULL))
            rep(j, n) res[i][j] = 1;
        if (!tb[i] && (((vb[i]) >> pos) & 1ULL))
            rep(j, n) res[j][i] = 1;
    }
    rep(i, n) rep(j, n) {
        if (ta[i] == tb[j]) {
            auto a = ((va[i] >> pos) & 1ULL);
            auto b = ((vb[j] >> pos) & 1ULL);
            if (!ta[i])
                res[i][j] = a | b;
            else
                res[i][j] = a & b;
        }
    }
    f2(pos);
    transpose();
    f2(pos);
    transpose();
    rep(i, n) rep(j, n)
        ans[i][j] += ((ull)(res[i][j]) << pos);
}
bool check() {
    rep(i, n) {
        ull an = -1;
        ull o = 0;
        ull an2 = -1;
        ull o2 = 0;
        rep(j, n) {
            an &= ans[i][j];
            o |= ans[i][j];
            an2 &= ans[j][i];
            o2 |= ans[j][i];
        }
        if ((!ta[i] && an != va[i]) || (ta[i] && o != va[i]) ||
            (!tb[i] && an2 != vb[i]) || (tb[i] && o2 != vb[i]))
            return false;
    }
    return true;
}
void solve() {
    cin >> n;
    rep(i, n) cin >> ta[i];
    rep(i, n) cin >> tb[i];
    rep(i, n) cin >> va[i];
    rep(i, n) cin >> vb[i];
    rep(i, 64) f(i);

    if (check())
        rep(i, n) rep(j, n) cout << ans[i][j] << (j < n - 1 ? ' ' : '\n');
    else
        cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    cout.flush();
    return 0;
}
