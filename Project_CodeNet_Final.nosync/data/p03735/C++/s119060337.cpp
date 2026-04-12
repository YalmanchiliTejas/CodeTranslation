#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
ll x[220000];
ll y[220000];
vector<pair<int, int> > vv;
int cc[220000];

int main() {
    cin >> n;
    ll mn1 = 1e9;
    ll mn2 = 1e9;
    ll mx1 = 0;
    ll mx2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
        mn1 = min(mn1, x[i]);
        mn2 = min(mn2, y[i]);
        mx1 = max(mx1, x[i]);
        mx2 = max(mx2, y[i]);
    }
    ll ans = (mx1 - mn1) * (mx2 - mn2);
    ll now = max(mx1, mx2) - min(mn1, mn2);
    for (int i = 0; i < n; ++i)
        vv.push_back(make_pair(x[i], i)), vv.push_back(make_pair(y[i], i));
    sort(vv.begin(), vv.end());
    int cur = 0;
    int cb = n;
    for (int i = 0; i < vv.size(); ++i) {
        while (cur < vv.size() && cb) {
            ++cc[vv[cur].second];
            if (cc[vv[cur].second] == 1)
                --cb;
            ++cur;
        }
        if (cb)
            break;
        ans = min(ans, now * (vv[cur - 1].first - vv[i].first));
        --cc[vv[i].second];
        if (cc[vv[i].second] == 0)
            ++cb;
    }
    cout << ans << "\n";
    return 0;
}


