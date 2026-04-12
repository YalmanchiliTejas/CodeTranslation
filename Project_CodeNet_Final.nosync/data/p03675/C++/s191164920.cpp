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

deque<i32> q;

void solve() {
    indef(i32, n);
    times(n, ai) {
        indef(i32, a);
        if ((n&1) == (ai&1))
            q.push_back(a);
        else
            q.push_front(a);
    }
    while (q.size()-1) {
        cout << q.front() << " ";
        q.pop_front();
    } cout << q.front() << endl;
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
    solve();

    return 0;
}