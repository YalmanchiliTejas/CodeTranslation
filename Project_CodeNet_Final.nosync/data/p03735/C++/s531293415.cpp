#define taskname "test"

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> pii;

const int inf = 1e9 + 9;

int n;
vector<int> x, y;

void read_input()
{
    cin >> n;
    x.resize(n); y.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
}

lli calc1(vector<int> x, vector<int> y)
{
    for(int i = 0; i < n; ++i)
        if(x[i] > y[i]) swap(x[i], y[i]);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return (x[n - 1] - x[0]) * 1LL * (y[n - 1] - y[0]);
}

lli calc2(vector<int> x, vector<int> y)
{
    vector<pii> v;
    int mn = inf, mx = -inf;
    multiset<int> ms;
    for(int i = 0; i < n; ++i)
    {
        if(x[i] > y[i]) swap(x[i], y[i]);
        v.push_back(pii(x[i], y[i]));
        mn = min(mn, x[i]);
        mx = max(mx, y[i]);
        ms.insert(x[i]);
    }
    sort(v.begin(), v.end());
    lli res = inf * 1LL * inf;
    for(int i = 0; i < n; ++i)
    {
        ms.erase(ms.find(v[i].fi));
        ms.insert(v[i].se);
        res = min(res, (mx - mn) * 1LL * (*ms.rbegin() - *ms.begin()));
    }
    return res;
}

void solve()
{
    cout << min(calc1(x, y), calc2(x, y)) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read_input();
    solve();
}

