#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define in insert

#define pii pair<ll, ll>
#define ll long long
#define lb long double

#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define m_p(i, j) make_pair(i, j)
#define mem(a, x) memset(a, x, sizeof(a))
#define endl "\n"
#define all(x) x.begin(), x.end()

const ll mod = 1e9 + 7;
const ll maxn = 6e5 + 7;
ll n, a[maxn];
int main()
{
    ll sum = 0, tot = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], sum += a[i], sum %= mod, tot += a[i] * a[i], tot %= mod;
    sum *= sum;
    sum %= mod;
    sum -= tot;
    sum += mod;
    sum %= mod;
    if (sum % 2 == 0)
        cout << sum / 2 << endl;
    else {
        sum += mod;
        cout << sum / 2 << endl;
    }
}
