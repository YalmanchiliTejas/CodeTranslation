#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define printd(x) printf("%.12f\n", ans);
#define print(x) cout << (x) << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;
#define YES() cout << "YES" << endl;
#define NO() cout << "NO" << endl;
#define all(x) (x).begin(),(x).end()
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(void) {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 1001001001;
    for (int i = 0; i < 200005; i += 2) {
        ll sum = 0;
        sum += i * c;
        sum += max(0LL, (x - (i / 2))) * a + max(0LL, (y - (i / 2))) * b;
        chmin(ans, sum);
    }
    
    cout << ans << endl;
    return 0;
}