#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <fstream>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <iomanip>
#define memtst(x) (sizeof(x) / 1024. / 1024.)
#define mem0(x) memset((x), 0, (sizeof x))
#define meminf(x) memset((x), INF, (sizeof x))
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define pq std::priority_queue
#define iter iterator
#define mp(x, y) std::make_pair((x), (y))
#define fst first
#define sec second
#define lc(x) ((x) * 2)
#define rc(x) ((x) * 2 + 1) 
#define md(x, y) (((x) + (y)) / 2)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair <int, int> pii;
const double PI = acos(-1);
const double EPS = 1e-6;
const ll MOD = 998244353;
const ll INF = 0x3F3F3F3F;
template <typename T>
inline T Abs(T x)
{
    return x < 0 ? x * -1 : x;
}
template <typename T>
inline T Max(T x, T y, T z)
{
    return std::max(std::max(x, y), z);
}
template <typename T>
inline T Min(T x, T y, T z)
{
    return std::min(std::min(x, y), z);
}
template <typename T>
inline T Ckmax(T &x, T y)
{
    return x = std::max(x, y);
}
template <typename T>
inline T Ckmin(T &x, T y)
{
    return x = std::min(x, y);
}
template <typename T>
inline T Sqr(T x)
{
    return x * x;
}
template <typename T>
inline T Pow(T x, T y)
{
    T r = 1;
    while (y > 0)
    {
        if (y % 2 > 0)
            (r *= x) %= MOD;
        (x *= x) %= MOD;
        y /= 2;
    }
    return r % MOD;
}
template <typename T>
T Pow(T x, T y, T z)
{
    T r = 1;
    while (y > 0)
    {
        if (y % 2 > 0)
            (r *= x) %= z;
        (x *= x) %= z;
        y /= 2;
    }
    return r % z;
}
template <typename T>
inline T gcd(T x, T y)
{
    return y > 0 ? gcd(y, x % y) : x;
}
template <typename T>
inline T lcm(T x, T y)
{
    return x / gcd(x, y) * y;
}
inline void cinspu(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
}
inline ll read(void)
{
    char x;
    while (x = getchar(), x != '-' && !isdigit(x))
        ;
    char flg = x == '-';
    ll num = (flg ? getchar() : x) - '0';
    while (isdigit(x = getchar()))
        (num *= 10) += x - '0';
    return flg ? -num : num;
}
const int N = 50 + 10;
const int one[6] = {0, 0, 1, 2, 3, 3};
ll a[N], p[N];
ll dfs(ll n, ll x)
{
	if (x <= 1)
		return 0;
	if (n == 1)
		return one[x];
	if (x == a[n])
		return p[n];
	ll val = 0;
	val += dfs(n - 1, std::min(x - 1, p[n] - 2));
	if (x >= p[n])
		val += 1 + dfs(n - 1, x - p[n] - (x >= a[n]));
	return val;
}
int main()
{
	cinspu();
	ll n, x;
	std::cin >> n >> x;
	p[0] = 1;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] * 2 + 1;
	a[0] = 1;
	for (int i = 1; i <= n; ++i)
		a[i] = a[i - 1] * 2 + 3;
	std::cout << dfs(n, x) << std::endl;
	return 0;
}