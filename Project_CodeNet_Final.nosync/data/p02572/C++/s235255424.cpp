#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
const int INF = 0x3f3f3f3f;
const int maxn = 1100000;
const int mod = 1e9 + 7;
ll a[maxn];
ll sum[maxn];
void exgcd(ll a, ll b, ll &x, ll &y, ll &d)
{
    if (!b)
    {
        d = a, x = 1, y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
ll inv(ll t, ll p)
{ //如果不存在，返回-1
    ll d, x, y;
    exgcd(t, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}
void run_case()
{
    int n;
    cin >> n;
    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        tot += a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll cur = tot - sum[i];
        ans = (ans + cur % mod * a[i] % mod) % mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    run_case();
    cout.flush();
    return 0;
}