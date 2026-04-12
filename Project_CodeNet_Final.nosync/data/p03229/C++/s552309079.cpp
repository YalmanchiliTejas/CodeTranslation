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
    int n; cin >> n;
    deque<ll> as(n); 
    rep(i, n) cin >> as[i];
    sort(all(as));
    ll l, r;
    ll ans = 0;
    while (!as.empty()) {
        if (as.size() == 1) {
            ll m = as.front();
            as.pop_back();;
            ans += max(r-m, m-l);
            break;
        }
        ll l2 = as.front(), r2 = as.back();
        if (as.size() == n) {
            ans += r2 - l2;
        } else {
            ans += r2 - l; 
            ans += r - l2;
        } 
        l = l2; 
        r = r2; 
        as.pop_back(); as.pop_front();

    } 
    cout << ans << endl;
    return 0;
}