#ifdef _MSC_VER
#  define _CRT_SECURE_NO_WARNINGS
#  define _USE_MATH_DEFINES
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long int; using f64 = double;
using u32 = unsigned int; using u64 = unsigned long long int; using str = string;
template <typename T> using vec = vector<T>; void in() { }
template <typename T, typename...TS> void in(T &&x, TS &&...xs) { cin >> x; in(move(xs)...); }
template <typename T> void out(T &&x) { cout << x << "\n"; }
template <typename T, typename...TS> void out(T &&x, TS &&...xs) { cout << x << " "; out(move(xs)...); }
#define indef(t, ...) t __VA_ARGS__; in(__VA_ARGS__)
#define get(t) []{ t x; cin >> x; return x; }()
#define times(n, i) for (i32 i = 0; i < (n); ++i)
#define range(a, b, i) for (i32 i = (a); i < (b); ++i)
#define upto(a, b, i) for (i32 i = (a); i <= (b); ++i)
#define downto(a, b, i) for (i32 i = (a); i >= (b); --i)
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define even(x) ((abs(x) & 1) == 0)
#define odd(x) ((abs(x) & 1) == 1)
#define bit(x, i) (((x) >> i) & 1)
#define append emplace_back
#define bisect_left lower_bound
#define bisect_right upper_bound
#define bound(a, x, b) (a <= x && x <= b)
const i64 MOD = 1000000007ll;
const f64 EPS = 1e-10;

struct unionfind {
    vec<i32> data;
    unionfind(i32 size) : data(size, -1) { }
    void unite(i32 x, i32 y) {
        x = find(x); y = find(y); if (x == y) return;
        if (data[y] < data[x]) swap(x, y); data[x] += data[y]; data[y] = x;
    }
    i32 find(i32 x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
    i32 size(i32 x) { return -data[find(x)]; }
    bool same(i32 x, i32 y) { return find(x) == find(y); }
};

 i64 solve() {
     indef(i32, n);
     vec<pair<i32, i32>> xs(n), ys(n);
     times(n, ni) {
         in(xs[ni].first, ys[ni].first);
         xs[ni].second = ys[ni].second = ni;
     }
     sortall(xs); sortall(ys);
     vec<tuple<i32, i32, i32>> es;
     times(n-1, ni) {
         i32 d = xs[ni+1].first - xs[ni].first;
         i32 a = xs[ni].second;
         i32 b = xs[ni+1].second;
         es.append(make_tuple(d, a, b));
     }
     times(n-1, ni) {
         i32 d = ys[ni+1].first - ys[ni].first;
         i32 a = ys[ni].second;
         i32 b = ys[ni+1].second;
         es.append(make_tuple(d, a, b));
     }
     sortall(es);
     i64 ans = 0;
     unionfind uf(n);
     times(es.size(), ei) {
         i32 d, a, b;
         tie(d, a, b) = es[ei];
         if (uf.same(a, b)) continue;
         uf.unite(a, b);
         ans += d;
     }
     return ans;
}

i32 main()
{
    ios::sync_with_stdio(false);

#ifdef _MSC_VER
    /**
    ifstream fin("input.txt"); cin.rdbuf(fin.rdbuf()); assert(fin);
    ofstream fout("output.txt"); cout.rdbuf(fout.rdbuf()); assert(fout);
    /**/
#endif

    cout << fixed << setprecision(9);
    out(solve());

    return 0;
}