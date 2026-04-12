#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct _IO { _IO() { ios::sync_with_stdio(0); cin.tie(0); } } _io;
typedef long long ll; typedef long double db;

int exgcd(int a, int b, int& x, int& y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
int getInv(int a, int mod)
{
    int x, y;
    return exgcd(a, mod, x, y) == 1 ? (x % mod + mod) % mod : -1;
}

ll mod = 1e9 + 7;

int main()
{
    int N;
    cin >> N;
    vector<ll> a(N);
    ll t = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        a[i] %= mod;
        t = ((t % mod) + a[i]) % mod;
    }
    t = (t * t) % mod;
    for (int i = 0; i < N; ++i)
    {
        t = ((t % mod) - (a[i] * a[i]) % mod + mod) % mod;
    }
    t = ((t % mod) * getInv(2, mod)) % mod;
    cout << t << endl;
    return 0;
}