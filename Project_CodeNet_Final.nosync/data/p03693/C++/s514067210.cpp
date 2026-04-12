#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long int; using f64 = double; using str = string;
template <typename T> using vec = vector<T>;
template <typename T> using heap = priority_queue<T>;
void in() {}; template <typename T, typename...TS> void in(T &&x, TS &&...xs) { cin>>x; in(move(xs)...); };
template <typename T> void _out(const char *sep, const char *end, T &&x) { cout<<x<<end; };
template <typename T, typename...TS> void _out(const char *sep, const char *end, T &&x, TS &&...xs) { cout<<x<<sep; _out(sep, end, move(xs)...); }
#define indef(t, ...) t __VA_ARGS__; in(__VA_ARGS__)
#define get(t) []{ t _; cin >> _; return _; }()
#define put(...) _out("", "", __VA_ARGS__)
#define out(...) _out(" ", "\n", __VA_ARGS__)
#define times(n, i) for (i32 i =  0 ; i <  (n); ++i)
#define range(a, b, i) for (i32 i = (a); i <  (b); ++i)
#define upto(a, b, i) for (i32 i = (a); i <= (b); ++i)
#define downto(a, b, i) for (i32 i = (a); i >= (b); --i)
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define even(x) (((x) & 1) == 0)
#define odd(x) (((x) & 1) == 1)
#define append emplace_back
#define findge lower_bound
#define findgt upper_bound
const i64 MOD = 1000000007;
const f64 EPS = 1e-10;

i64 r,g,b;

i32 main()
{
    in(r, g, b);
    r = (r-'0')*100;
    g = (g-'0')*10;
    b = (b-'0')*1;
    i64 n = r+g+b;
    out((n % 4) == 0 ? "YES" : "NO");
    return 0;
}