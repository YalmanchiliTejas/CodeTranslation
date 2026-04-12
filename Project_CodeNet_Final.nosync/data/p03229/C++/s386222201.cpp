#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define inf (int)1e9+7
#define eb emplace_back

/*
 2回足すか2回引くか1回足して1回引くか
 2回足すのはでかく、2回引くのは小さくしたい
 slsl...
 と並べる
 (l - s) + (l - s) + ...
 となる
 
 1. n % 2 == 0
 slsl...sl
 lsls...lsと同値
 l, sの数同じで端がl, s1個ずつだから
 
 2. n % 2 != 0
 真ん中のやつをsとするかlとするか
 s, lどっちか多くなる
 slsl...sls (内っ側のl all * 2)
 lsls...lsl (一番外のl1回ずつ足す)
 
 */
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    ll a[n]; rep(i, n) cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    if (n % 2 == 0) {
        int k = n / 2 - 1;
        rep(i, k) ans -= 2 * a[i];
        ans -= a[k];
        ans += a[k + 1];
        rrep(i, k + 2, n) ans += 2 * a[i];
    } else {
        //slsl...sls
        int k = n / 2;
        rep(i, k) ans += 2 * a[n - 1 - i];
        rep(i, k - 1) ans -= 2 * a[i];
        ans -= a[k - 1];
        ans -= a[k];
        //lsls...lsl
        ll tmp = 0;
        rep(i, k) tmp -= 2 * a[i];
        rep(i, k - 1) tmp += 2 * a[n - 1 - i];
        tmp += a[k];
        tmp += a[k + 1];
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
