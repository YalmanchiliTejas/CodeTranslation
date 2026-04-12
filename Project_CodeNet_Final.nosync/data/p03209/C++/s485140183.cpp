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
i64 d[] = { 0,1,2,3,6,7,14,15,30,31,62,63,126,127,254,255,510,511,1022,1023,2046,2047,4094,4095,8190,8191,16382,16383,32766,32767,65534,65535,131070,131071,262142,262143,524286,524287,1048574,1048575,2097150,2097151,4194302,4194303,8388606,8388607,16777214,16777215,33554430,33554431,67108862,67108863,134217726,134217727,268435454,268435455,536870910,536870911,1073741822,1073741823,2147483646,2147483647,4294967294,4294967295,8589934590,8589934591,17179869182,17179869183,34359738366,34359738367,68719476734,68719476735,137438953470,137438953471,274877906942,274877906943,549755813886,549755813887,1099511627774,1099511627775,2199023255550,2199023255551,4398046511102,4398046511103,8796093022206,8796093022207,17592186044414,17592186044415,35184372088830,35184372088831,70368744177662,70368744177663,140737488355326,140737488355327,281474976710654,281474976710655,562949953421310,562949953421311,1125899906842622,1125899906842623 };
bool eat(i64 l, i64& x, i64& t)
{
	if (l == 0)
	{
		x--;
		t++;
		return x == 0;
	}
	l -= 1;
	x--;//bread
	if (x == 0) return true;
	i64 all = d[2 * l] + d[2 * l + 1];
	if (x >= all)
	{
		t += d[2 * l + 1];
		x -= all;
	}
	else if (eat(l, x, t))return true;
	if (x == 0) return true;
	x--; t++;
	if (x == 0) return true;
	if (x >= all)
	{
		t += d[2 * l + 1];
		x -= all;
	}
	else if (eat(l, x, t))return true;
	if (x == 0) return true;
	x--;
	return x == 0;
}
int main()
{
	din(i64, n, x);
	i64 t = 0;
	eat(n, x, t);
	dout(t);
}