#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

LL k, n, t[51];

LL suf(LL a, LL b)
{
    if(a % b == 0) return a / b;
    return a / b + 1;
}

bool check(LL x)
{
    // t[i] - y * n + (x - y) <= n - 1
    // - y * (n + 1) <= n - 1 - x - t[i]
    // y >= (-n + 1 + x + t[i]) / (n + 1)
    LL sm = 0;
    for(int i = 0; i < n; i++)
    {
        LL y = 0;
        if(t[i] + x + 1 - n > 0)
            y = suf(t[i] + x + 1 - n, n + 1);
        sm += y;
    }
    return sm <= x;
}

LL bin_search(LL l, LL r)
{
    while(l + 1 < r)
    {
        LL m = (l + r) / 2;
        check(n * m) ? r = m : l = m;
    }
    return r;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    LL val = n * bin_search(-1, 1e17);
    for(int i = 1000 * n - 1; i >= 0; i--)
    {
        if(val - i < 0) continue;
        if(check(val - i))
        {
            cout << val - i << "\n";
            return 0;
        }
    }
    return 0;
}
