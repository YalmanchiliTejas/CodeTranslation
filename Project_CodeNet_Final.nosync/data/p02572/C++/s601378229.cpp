#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf (int)(1e18)
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(p) p.begin(), p.end()
#define ub(a, b) upper_bound(all(a), b)
#define lb(a, b) lower_bound(all(a), b)
#define sz(x) (int)x.size()
#define PI 3.14159265
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void run()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solution()
{
    int n;
    cin >> n;
    int ans = 0;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += (a[i] * sum);
        ans %= mod;
        sum += a[i];
        sum %= mod;
    }
    cout << ans << endl;
    return;
}
int32_t main()
{
    run();
    solution();
    return 0;
}