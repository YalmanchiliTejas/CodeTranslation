#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> p;
const int N = 100005;

int n, a[N], b[N], par[N];
vector<ii> va, vb;
vector<p> v;

int find(int x) {
    return (x == par[x]) ? x : par[x] = find(par[x]);
}

bool join(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    par[x] = y; return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) par[i] = i;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        va.push_back(ii(a[i], i));
        vb.push_back(ii(b[i], i));
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (int i = 1; i < n; ++i) {
        v.push_back(p(va[i].fi - va[i - 1].fi, ii(va[i].se, va[i - 1].se)));
        v.push_back(p(vb[i].fi - vb[i - 1].fi, ii(vb[i].se, vb[i - 1].se)));
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (join(v[i].se.fi, v[i].se.se)) {
            res += v[i].fi;
        }
    }
    cout << res;
}
