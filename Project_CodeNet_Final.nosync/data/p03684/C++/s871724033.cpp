#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define ms(x, v) memset(x, v, sizeof(x))
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
#define pii pair<int, int>
pii s[N];
int id1[N], id2[N];
bool cmp1(int i, int j)
{
    return s[i].first < s[j].first;
}
bool cmp2(int i, int j)
{
    return s[i].second < s[j].second;
}
int pa[N];
int fpa(int x) {return pa[x] == x ? x : pa[x] = fpa(pa[x]); }

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    rep(i, n) cin >> s[i].first >> s[i].second;
    rep(i, n) pa[i] = id1[i] = id2[i] = i;
    sort(id1, id1 + n, cmp1);
    sort(id2, id2 + n, cmp2);
    vector<pair<int, pii> > v;
    rep(i, n - 1) v.push_back({s[id1[i + 1]].first - s[id1[i]].first, {id1[i], id1[i + 1]}});
    rep(i, n - 1) v.push_back({s[id2[i + 1]].second - s[id2[i]].second, {id2[i], id2[i + 1]}});
    sort(v.begin(), v.end());
    ll ans = 0;
    for(auto x : v)
    {
        if(fpa(x.second.first) == fpa(x.second.second)) continue;
        ans += x.first;
        pa[fpa(x.second.first)] = fpa(x.second.second);
    }
    cout << ans << endl;
    return 0;
}
