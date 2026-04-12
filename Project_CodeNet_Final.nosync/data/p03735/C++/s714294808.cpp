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

const int N = 200000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 31;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //int TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    ll n;
    cin >> n;
    vector<vector<ll> > a(n, vector<ll> (2));
    rep(i, 0, n)
        cin >> a[i][0] >> a[i][1];
    ll ma = max(a[0][0], a[0][1]), mi = min(a[0][0], a[0][1]);
    rep(i, 1, n)
    {
        ma = max(ma, max(a[i][0], a[i][1]));
        mi = min(mi, min(a[i][0], a[i][1]));
    }
    ll ans = big;
    vector<pair<ll, ll> > b(n * 2);
    rep(i, 0, n)
    {
        b[i * 2] = {a[i][0], i};
        b[i * 2 + 1] = {a[i][1], i};
    }
    sort(b.begin(), b.end());
    int cnt[n], curr = 0;
    fill(cnt, cnt + n, 0);
    for (int l = 0, r = -1; l < n * 2; l++)
    {
        while (curr < n)
        {
            if (r == n * 2 - 1)
                break;
            r++;
            cnt[b[r].se]++;
            if (cnt[b[r].se] == 1)
                curr++;
        }
        if (curr == n)
            ans = min(ans, (ma - mi) * (b[r].fi - b[l].fi));
        cnt[b[l].se]--;
        if (cnt[b[l].se] == 0)
            curr--;
    }
    ll t1 = ma, t2 = mi;
    rep(i, 0, n)
    {
        if (a[i][0] < a[i][1])
            swap(a[i][0], a[i][1]);
        t1 = min(t1, a[i][0]);
        t2 = max(t2, a[i][1]);
    }
    ans = min(ans, (ma - t1) * (t2 - mi));
    cout << ans << endl;
}
