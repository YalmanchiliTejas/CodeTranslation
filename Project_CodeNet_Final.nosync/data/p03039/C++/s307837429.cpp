#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

#define MAX_P 200010
int fact[MAX_P]; //n! mid p

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
int mod_inverse(int a, int m)
{
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
//n! = a p^e -> a mod p
void make_fact()
{
    fact[1] = 1;
    for (int i = 2; i < MAX_P; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return;
}
int mod_fact(int n, int p, int &e)
{
    e = 0;
    if (n == 0)
        return 1;
    int res = mod_fact(n / p, p, e);
    e += n / p;
    if (n / p % 2 != 0)
        return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}
//nCk mod p
int mod_comb(int n, int k, int p)
{
    if (n < 0 || k < 0 || n < k)
        return 0;
    int e1, e2, e3;
    int a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
    if (e1 > e2 + e3)
        return 0;
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    make_fact();
    int tmp = mod_comb(n * m - 2, k - 2, mod);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + (i * (n - i) * m * m) % mod) % mod;
    for (int i = 1; i <= m; i++)
        ans = (ans + (i * (m - i) * n * n) % mod) % mod;
    ans = (ans * tmp) % mod;
    cout << ans << endl;
}