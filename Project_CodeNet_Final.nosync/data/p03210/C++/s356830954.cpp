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
const ll N = 1e5 + 10;
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
inline void Ckmax(T &x, T y)
{
    x = std::max(x, y);
}
template <typename T>
inline void Ckmin(T &x, T y)
{
    x = std::min(x, y);
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
inline ll fac(ll x)
{
	ll r = 1;
	for (; x > 1; --x)
		(r *= x) %= MOD;
	return r;
}


int main()
{
	cinspu();
	int x;
	std::cin >> x;
	std::cout << (x == 3 || x == 5 || x == 7 ? "YES" : "NO");
	return 0;
}