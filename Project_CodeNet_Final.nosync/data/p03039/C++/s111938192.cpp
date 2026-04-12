#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

ll fastPow(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll fac[1123456];
void combInit(int mx)
{
    fac[0] = 0;
    fac[1] = 1;
    for (int i = 2; i <= mx; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll modDiv(ll a, ll b)
{
    return a * fastPow(b, MOD - 2) % MOD;
}

ll comb(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (a < b)
        return 0;
    if (a <= 0 || b < 0)
        return 0;
    if (a == b)
        return 1;

    ll p, c;

    c = modDiv(fac[a], fac[a - b]);
    p = fac[b];

    ll res = modDiv(c, p);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    combInit(212345);

    ll n, m;
    ll k;
    cin >> n >> m >> k;

    ll t = comb(n * m - 2, k - 2);

    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        ll s = 0;

        (s += (n - i) * m % MOD * m % MOD * i % MOD) %= MOD;

        (res += s) %= MOD;
    }
    for (int i = 1; i < m; i++)
    {
        ll s = 0;

        (s += (m - i) * n % MOD * n % MOD * i % MOD) %= MOD;

        (res += s) %= MOD;
    }

    (res *= t) %= MOD;

    cout << res << endl;

    return 0;
}
