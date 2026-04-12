#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define y1 dhwjdshg

using namespace std;

const int N = 200000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

ll f(ll n, ll b)
{
    ll v = n / b;
    ll ans = (v - 1) * v / 2 * b;
    ans += (n - n / b * b + 1) * v;
    return ans;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    rep(b, k + 1, n + 1)
    {
        ans += (b - k);
        ans += f(n - k, b) - f(n - b, b);
    }
    if (k == 0)
        ans -= n;
    cout << ans << "\n";
    return 0;
}