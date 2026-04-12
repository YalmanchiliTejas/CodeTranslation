#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const llint INF = 1000000000000000000LL;

llint n, mn, mx, sol = INF;
llint x[MAXN], y[MAXN];
vector < pair <llint, llint> > v;
multiset <int> ms;
multiset <int> :: iterator it;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
        v.push_back(make_pair(x[i], y[i]));
    }
    sort(v.begin(), v.end());
    int ind;
    for (int i=0; i<n; i++) {
        x[i] = v[i].first, y[i] = v[i].second;
        if (y[i] > mx) {
            mx = y[i];
            ind = i;
        }
    }
    mn = x[0];
    if (mx == y[0]) {
        llint z = mx;
        for (int i=0; i<n; i++) {
            z = min(z, y[i]);
        }
        llint res = (x[n-1] - mn) * (mx - z);
        sol = min(sol, res);
    } else {
        llint z = mx;
        for (int i=0; i<n; i++) {
            if (i == ind) continue;
            z = min(z, y[i]);
        }
        llint res = (x[n-1] - mn) * (mx - z);
        sol = min(sol, res);
        //dfsdf
        llint a = y[0], b = x[ind], lim = 0, lo = INF;
        if (a > b) swap(a, b);
        for (int i=1; i<n; i++) {
            if (i == ind) continue;
            lim = max(lim, x[i]);
            lo = min(lo, x[i]);
        }
        lim = max(lim, b);
        lo = min(lo, a);
        res = (mx - mn) * (lim - lo);
        sol = min(res, sol);
        for (int i=1; i<n; i++) {
            if (i == ind) continue;
            ms.insert(x[i]);
        }
        for (int i=1; i<n; i++) {
            if (i == ind) continue;
            ms.erase(ms.find(x[i]));
            ms.insert(y[i]);
            lo = *ms.begin();
            it = ms.end(); it--;
            lim = *it;
            lo = min(lo, a);
            lim = max(lim, b);
            res = (mx - mn) * (lim - lo);
            sol = min(sol, res);
        }
    }
    cout << sol;
    return 0;
}
