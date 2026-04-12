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

using namespace std;

const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll ans = 0;
    while (true)
    {
        if (a[0] < 1000)
            break;
        int p = 0;
        while (p < n && (a[0] - a[p]) < (n + 1))
            p++;
        if (p == n)
        {
            ll cnt = max(0LL, a[0] - 1000);
            ans += cnt * n;
            rep(i, 0, n)
                a[i] -= cnt;
            break;
        }
        ll cnt = (a[0] - a[p]) / (n + 1);
        ans += p * cnt;
        rep(i, 0, n)
            if (i < p)
                a[i] -= (n - p + 1) * cnt;
            else
                a[i] += p * cnt;
    }
    while (true)
    {
        int p = 0;
        rep(i, 0, n)
            if (a[i] > a[p])
                p = i;
        if (a[p] < n)
            break;
        ans++;
        rep(i, 0, n)
            if (i != p)
                a[i]++;
            else
                a[i] -= n;
    }
    cout << ans << "\n";
    return 0;
}
