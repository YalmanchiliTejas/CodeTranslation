#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll rec(ll n, ll x)
{
    if (n == 0)
        return 1;
    ll a = (1LL << (n + 1)) - 3;
    ll p = (1LL << n) - 1;
    if (x == 1)
        return 0;
    else if (x <= a + 1)
        return rec(n - 1, x - 1);
    else if (x == a + 2)
        return p + 1;
    else if (x <= 2 * a + 2)
        return p + 1 + rec(n - 1, x - a - 2);
    else if (x == 2 * a + 3)
        return 2 * p + 1;
}

int main()
{
    ll n, x;
    cin >> n >> x;

    OP(rec(n, x));

    return 0;
}