#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300200];
int t[1300200];

void upd(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
        t[v] = val;
    else
    {
        int m = tl + tr >> 1;
        if (pos <= m) upd(2 * v, tl, m, pos, val);
        else upd(2 * v + 1, m + 1, tr, pos, val);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int m = tl + tr >> 1;
    return max(get(2 * v, tl, m, l, min(r, m)), get(2 * v + 1, m + 1, tr, max(l, m + 1), r));
}

signed main()
{
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; ++i)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    int ma = 0;
    for(int i = 0; i < n; ++i)
    {
        int cur = a[i];
        int lst = get(1, 0, 3e5, cur, 3e5);
        lst++;
        upd(1, 0, 3e5, cur, lst);
        ma = max(ma, lst);
    }
    cout << ma << '\n';
    return 0;
}
