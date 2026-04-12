#include <bits/stdc++.h>

//{{{
#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
// clang-format off
void _print() { cerr << "]\033[0m\n"; }
template <typename T> void __print(T x) { cerr << x; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifdef LOCAL
#define debug(x...) cerr << "\033[1;34m[" << #x << "] = \033[1;32m["; _print(x)
#define debug_arr(x...) cerr << "\033[1;34m[" << #x << "] = \033[1;32m" << (x) << "\033[0m\n"
#else
#define debug(x...)
#define debug_arr(x...)
#endif
// clang-format on
//}}}

int T;

const int mod = 1e9 + 7;
const int N = 1e4 + 10;
const int K = 110;

int n;
int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        if (n >= 30)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
