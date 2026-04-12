#include <bits/stdc++.h>
using namespace std;

#define ENGZ ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define sfi(x) scanf("%d" , &x)
#define sfi2(x, y) scanf("%d%d" , &x,&y)
#define sfl2(x, y) scanf("%I64d%I64d" , &x,&y)
#define sfl(x) scanf("%I64d" , &x)
#define sfl3(x, y, z) scanf("%I64d%I64d%I64d", &x, &y, &z)
#define sfd(x) scanf("%lf", &x)
#define sfd2(x, y) scanf("%lf", &x, &y)
#define sfs(x) scanf("%s", &x)
#define testv(x) cerr << x << ' '
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define test cerr << "here"
#define fst(x) cout << fixed << setprecision(x)
#define mod 1000000007
#define pi (2 * acos(0))
typedef long double ld;
typedef long long ll;

int par[200005], rnk[200005];

int findp(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = findp(par[x]);
}

bool iscon(int x, int y)
{
    if (findp(x) == findp(y))
        return true;
    return false;
}

void con(int x, int y)
{
    int px = findp(x), py = findp(y);
    if (rnk[px] > rnk[py])
        par[py] = px;
    else if (rnk[px] < rnk[py])
        par[px] = py;
    else
        par[px] = py, rnk[px]++;
}


    pair<pair<ll, ll>, int> a[100005], b[100005];
int main()
{
    ENGZ
    int n;
    ll ans = 0;
    for (int i = 0; i < 100005; i++)
        par[i] = i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second;
        b[i].first.first = a[i].first.second;
        b[i].first.second = a[i].first.first;
        a[i].second = b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    map<ll, vector<pair<int, int>>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        mp[abs(a[i].first.first - a[i + 1].first.first)].push_back({a[i].second, a[i + 1].second});
        mp[abs(b[i].first.first - b[i + 1].first.first)].push_back({b[i].second, b[i + 1].second});
    }
    for (auto it: mp)
    {
        for (auto i: it.second)
        {
            if (!iscon(i.first, i.second))
                con(i.first, i.second), ans += it.first;
        }
    }
    cout << ans;
    return 0;
}