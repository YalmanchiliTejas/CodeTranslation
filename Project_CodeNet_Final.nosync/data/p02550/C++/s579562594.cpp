#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f first
#define s second
#define sz(x) (int)x.size()
#define endl "\n"
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define gcd(a,b) __gcd((a),(b))
#define watch1(x) cout<<(x)<<endl
#define watch2(x,y) cout<<(x)<<" "<<(y)<<endl
#define watch3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

const int INF = 9e18;
const int mod = 998244353;
const int N = 1e5 + 5;

int i, n, x, m, pref[N];

void solve()
{
    cin >> n >> x >> m;
    if (n <= m)
    {
        int ans = 0;
        for (i = 1; i <= n; i++)
        {
            ans += x;
            x = (x * x) % m;
        }
        cout << ans;
        return;
    }
    int ans = 0, idx, final, rem;
    pref[0] = 0;
    map<int, int> vis;
    for (i = 1; i <= 2 * m; i++)
    {
        if (vis.find(x) == vis.end())
        {
            ans += x;
            vis[x] = i;
            pref[i] = pref[i - 1] + x;
            x = (x * x) % m;
        }
        else
        {
            idx = vis[x];
            final = i - 1;
            rem = n - i + 1;
            break;
        }
    }
    int steps = rem / (final - idx + 1), still = rem % (final - idx + 1);
    ans += steps * (pref[final] - pref[idx - 1]);
    ans += pref[idx + still - 1] - pref[idx - 1];
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
