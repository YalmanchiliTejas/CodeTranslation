#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long int ll;
using namespace std;
//分割数
ll n;
const int MAX_N = 200010;
const int M = 1000000007;

ll f[MAX_N], rf[MAX_N];
ll inv(ll x)
{
    ll res = 1;
    ll k = M - 2;
    ll y = x;
    while (k)
    {
        if (k & 1)
            res = (res * y) % M;
        y = (y * y) % M;
        k /= 2;
    }
    return res;
}
void init()
{
    f[0] = 1;
    rep(i, 1, MAX_N) f[i] = (f[i - 1] * i) % M;
    rep(i, 0, MAX_N) rf[i] = inv(f[i]);
}
//---------------------------------------------------------------------------------------------------
ll C(int n, int k)
{
    ll a = f[n];      // = n!
    ll b = rf[n - k]; // = (n-k)!
    ll c = rf[k];     // = k!

    ll bc = (b * c) % M;

    return (a * bc) % M;
}

int main()
{
    init();
    ll k, m;
    cin >> n >> m >> k;
    ll x = 0;
    ll y = 0;
    REP(i, m)
    {
        ll t = (i * (m - i)) % M;
        t = (t * ((n * n) % M)) % M;
        x += t;
        x %= M;
    }
    x *= C(n * m - 2, k - 2);
    x %= M;
    REP(i, n)
    {
        ll t = (i * (n - i)) % M;
        t = (t * ((m * m) % M)) % M;
        y += t;
        y %= M;
    }
    y *= C(n * m - 2, k - 2);
    cout << (x + y) % M << endl;
}