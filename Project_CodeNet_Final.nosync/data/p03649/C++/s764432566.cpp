//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    bool x = true;
    rep(i, n) {
        cin >> a[i];
        if(a[i] >= n) x = false;
    }
    if(x) {
        cout << 0 << endl;
        return 0;
    }

    vi r(n);
    rep(i, n) {
        r[i] = a[i]%(n+1);
    }

    ll ans = INT64_MAX;
    rep(i, n+1) {
        ll cnt = 0;
        rep(j, n) {
            int now = r[j]+i;
            now %= n+1;
            if(now == n) {
                cnt = -1;
                break;
            }
            cnt += a[j]-now;
            //cout << now << ' ' << j << ' ' << i << endl;
        }
        //cout << i << ' ' << cnt << endl;
        if(cnt >= 0) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
}