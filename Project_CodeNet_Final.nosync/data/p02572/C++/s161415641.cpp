
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define FAST_IO                                                                                                        \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl "\n"
#define db1(x) cout << #x << " = " << x << '\n';
#define db2(v)                                                                                                         \
    for (auto &x : v)                                                                                                  \
        cout << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    vt<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        sum = sum % MOD;
    }
    for (int i = 0; i < n - 1; i++)
    {
        sum -= a[i];
        if (sum < 0)
        {
            sum += MOD;
        }
        ans += a[i] * sum;
        ans = ans % MOD;
    }
    cout << ans;
    return 0;
}