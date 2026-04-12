#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define out(a) cout << a << endl
#define outv(v) rep(_, SZ(l)) cout << l[_] << " "; cout << endl
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    n = 10000;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> l;
    l.eb(a[0]);
    rep3(i, 1, n) {
        auto it = lower_bound(all(l), a[i]) - l.begin();
        //out("it " << it);
        if (it == 0) {
            l.insert(l.begin(), a[i]);
        } else {
            if (l[it - 1] != a[i]) l[it - 1] = a[i];
            else {
                l.insert(l.begin() + it, a[i]);
            }
        }
        //outv(l);
    }
    out(SZ(l));
}

