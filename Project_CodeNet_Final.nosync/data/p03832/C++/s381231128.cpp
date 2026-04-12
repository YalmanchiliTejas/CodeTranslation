#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <time.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{
    struct Small_Segment_Tree{
        vector<int> a;
        int l, r;

        private:
        int __summ(int L, int R, int l, int r, int v)
        {
            if (L <= l && r <= R)
                return a[v];
            if (R <= l || r <= L)
                return 0;
            int m = (l + r) / 2;
            return __summ(L, R, l, m, 2 * v + 1) + __summ(L, R, m, r, 2 * v + 2);
        }

        void __set(int P, int l, int r, int v, int V)
        {
            if (l + 1 == r)
            {
                a[v] = V;
                return;
            }
            int m = (l + r) / 2;
            if (P < m)
            {
                __set(P, l, m, 2 * v + 1, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
            else
            {
                __set(P, m, r, 2 * v + 2, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
        }

        public:
        int Summ(int L, int R)
        {
            if (R < L)
                return 0;
            return __summ(L, R + 1, l, r, 0);
        }

        void Set(int P, int V)
        {
            __set(P, l, r, 0, V);
        }

        Small_Segment_Tree(int _n)
        {
            a.resize(4 * _n);
            l = 0, r = _n;
        }
    };
    long long inq(long long x, long long q, long long MOD)
    {
        if (q == 0)
            return 1;
        long long l = inq(x, q / 2, MOD);
        if (q % 2)
            return l * l % MOD * x % MOD;
        return l * l % MOD;
    }
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
ll n, a, b, c, d;
ll rev[1200];
ll fact[1200];
ll cnk[1200][1200];
ll Psplit[1200][1200];

void split(ll n, ll g, ll h)
{
    ll ans = 1;
    ll i = n, j = g;
    for (int i = 0; i < g; i++)
    {
        ans = (ans * cnk[n][h]) % MOD;
        n -= h;
    }
    //cout << i << " " << j << " : " << ans << endl;
    Psplit[i][j] = ans;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    rev[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        rev[i] = inq(fact[i], MOD - 2, MOD);
    }
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i <= n; i++)
    {
        cnk[i][0] = cnk[i][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % MOD;
    for (int gs = a; gs <= b; gs++)
    {
        for (int gc = c; gc <= d; gc++)
        {
            if (gs * gc <= 1000)
                split(gc * gs, gc, gs);
        }
    }
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int gs = a; gs <= b; gs++)
    {
        vector<ll> dp2(n + 1);
        dp2 = dp;
        for (int gc = c; gc <= d; gc++)
        {
            for (int i = n - gs * gc; i >= 0; i--)
            {
                dp2[i + gs * gc] = (dp2[i + gs * gc] + dp[i] * cnk[i + gs * gc][i] % MOD * Psplit[gs * gc][gc] % MOD * rev[gc]) % MOD;
            }
        }
        dp = dp2;
    }
    cout << dp[n] % MOD;
}
