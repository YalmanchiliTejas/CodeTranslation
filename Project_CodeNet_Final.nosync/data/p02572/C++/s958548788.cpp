#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define ff first
#define ss second
#define pb push_back
 
int bexp(int a, int b, int mod)
{
    int res = 1;
    if (mod <= 0)
        return 0;
 
    while (b)
    {
        if (b & 1) res = (res * a) % mod;
 
        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}
 
#define N 300010
#define MOD 1000000007
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        return a.ss * (a.ff - a.ff / 2) > b.ss * (b.ff - b.ff / 2);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;

    int a[n];
    int c[n + 1] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        c[i + 1] = (c[i] + a[i]) % MOD;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        ans = (ans + a[i] * (c[n] - c[i + 1] + MOD) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}