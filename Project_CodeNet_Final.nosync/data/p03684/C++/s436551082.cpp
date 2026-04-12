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
const int P = 31;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

int p[N];
int r[N];

void build(int n)
{
    rep(i, 0, n)
        p[i] = i;
}

int get(int x)
{
    if (p[x] != x)
        p[x] = get(p[x]);
    return p[x];
}

bool uni(int x, int y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    if (r[x] >= r[y])
        p[y] = x;
    else
        p[x] = y;
    if (r[x] == r[y])
        r[x]++;
    return true;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 10.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n;
    cin >> n;
    pair<int, int> a[n], b[n];
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, i};
        b[i] = {y, i};
    }
    sort(a, a + n);
    sort(b, b + n);
    vector<pair<int, pair<int, int> > > e;
    rep(i, 0, n - 1)
        e.push_back({a[i + 1].fi - a[i].fi, {a[i].se, a[i + 1].se}});
    rep(i, 0, n - 1)
        e.push_back({b[i + 1].fi - b[i].fi, {b[i].se, b[i + 1].se}});
    sort(e.begin(), e.end());
    build(n);
    int ans = 0;
    for (auto it : e)
        if (uni(it.se.fi, it.se.se))
            ans += it.fi;
    cout << ans << endl;
    return 0;
}