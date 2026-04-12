#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N, X;
ll a[100], p[100];

ll cnt_p(int n, ll x)
{
    if (n == 0)
    {
        return 1;
    }
    if (x <= 1)
    {
        return 0;
    }
    else if (x <= 1 + a[n - 1])
    {
        return cnt_p(n - 1, x - 1);
    }
    else if (x == 2 + a[n - 1])
    {
        return p[n - 1] + 1;
    }
    else if (x <= 2 + 2 * a[n - 1])
    {
        return p[n - 1] + 1 + cnt_p(n - 1, x - a[n - 1] - 2);
    }
    else
    {
        return 2 * p[n - 1] + 1;
    }
}

int main()
{
    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;
    for (ll i = 1; i <= 50; i++)
    {
        a[i] = 3 + 2 * a[i - 1];
        p[i] = 2 * p[i - 1] + 1;
    }
    cout << cnt_p(N, X) << endl;
}
