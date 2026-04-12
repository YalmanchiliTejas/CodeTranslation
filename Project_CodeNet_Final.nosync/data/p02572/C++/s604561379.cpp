#define taskname "test"

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
int a[maxn];

int pref[maxn];

void read_input()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

int add(int x, int y)
{
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

void solve()
{
    pref[0] = 0;
    for(int i = 1; i <= n; ++i)
        pref[i] = add(pref[i - 1], a[i]);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = add(ans, a[i] * 1LL * pref[i - 1] % mod);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read_input();
    solve();
}

