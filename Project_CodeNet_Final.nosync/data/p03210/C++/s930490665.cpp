#include <bits/stdc++.h>
using namespace std;
// ==================================================
using i64 = int64_t; using u64 = uint64_t;
#define rep(i,a,b) for(i64 i=(int64_t)(a);i<(int64_t)(b);i++)
#define repn(i,n) rep(i,0,n)
#define din(t, ...) t __VA_ARGS__;_din(__VA_ARGS__)
#define v(t,n) vector<t> n
void _din() {} void dout() { cout << endl; }
template <typename T, typename ... Args> inline void _din(T& head, Args& ... rest) { cin >> head; _din(rest...); }
template <typename T, typename ... Args> inline void dout(T head, Args ... rest) { cout << head; if (sizeof...(rest)) cout << ' '; dout(rest...); }
template <typename T>inline void vsortg(vector<T>& v) { sort(v.begin(), v.end(), greater<T>()); }
template <typename T>inline void vsortl(vector<T>& v) { sort(v.begin(), v.end(), less<T>()); }
template <typename T> inline T nmax(T f1, T f2) { return max(f1, f2); }
template <typename T, typename ... Args> inline T nmax(T first, Args ... rest) { return nmax(first, nmax(rest...)); }
template <typename T> inline T nmin(T f1, T f2) { return min(f1, f2); }
template <typename T, typename ... Args> inline T nmin(T first, Args ... rest) { return nmin(first, nmin(rest...)); }
// ==================================================
int main()
{
	din(int, x);

	dout(x == 3 || x == 5 || x == 7 ? "YES" : "NO");
}