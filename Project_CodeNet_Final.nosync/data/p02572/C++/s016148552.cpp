#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
const ll mod = 1000000007;
int main()
{
    /*int d, t, s; cin >> d >> t >> s;
    if (d <= t * s) cout << "Yes" << endl;
    else cout << "No" << endl;
    */

    /*string s, t; cin >> s >> t;
    int mx = 0;
    rep(i, s.size()) {
        int tmp = 0;
        if (s.size() < i + t.size()) continue;
        rep(j, t.size()) {
            if (s[i + j] == t[j]) tmp++;
        }
        mx = max(mx, tmp);
    }
    cout << t.size() - mx << endl;
    */

    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n + 1, 0);
    sum[0] = 0;
    rep(i, n) {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
        sum[i + 1] %= mod;
    }
    ll ans = 0;
    rep(i, n) {
        ll s = sum.back() - sum[i + 1];
        s %= mod;
        if (s < 0) s += mod;
        ans += a[i] * s;
        ans %= mod;
    }
    cout << ans << endl;


    return 0;
}