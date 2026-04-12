#include <bits/stdc++.h>
#define pb push_back
#define vii vector<int>
#define task "ABC"
#define pll pair<ll, ll>
#define pii pair< ll, pair< ll, ll > >
#define fi first
#define se second

using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll mod = 1e9 + 7;
using namespace std;
const int N = 2e5+5;
ll tong, m, n, k, t, T, ntest, ans, u, v, b[N], P[N][20], lab[N], sum[N];
string s;
ll a[N], d[N][53];
vector<pii> kq;
vector<pll> adj[N], adt[N];
bool check;
inline void sol()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        a[i] = a[i] % mod;
    }
    b[n+1] = 0;
    for(int i = n; i > 0; i --)b[i] = (b[i+1] + a[i]) % mod;
    for(int i = 1; i < n; i ++)
    {
        ans = (ans + a[i] * b[i+1]) % mod;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();

}



