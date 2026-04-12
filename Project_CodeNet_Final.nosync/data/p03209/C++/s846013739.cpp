#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int n; ll x; 
    cin >> n >> x;
    vector<ll> as(n+1, 1), bs(n+1, 1);
    rep(i, n) as[i+1] = 2*as[i] + 3;
    rep(i, n) bs[i+1] = 2*bs[i] + 1;
    ll ans = 0;
    for(int i = n; i > 0; --i) {
        if (x == as[i]) {
            ans += bs[i];
            break;
        } 
        if (x >= 2 + as[i-1]) {
            ans += 1 + bs[i-1];
            x -= 2 + as[i-1];
        } else x -= 1;
        if (x < 2) {
            if (i == 1 && x == 1) ans += 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}