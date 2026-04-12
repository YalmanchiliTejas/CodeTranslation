#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]++;
    }

    vl v(n+1);  // v[i] : i番目(iは0-index)の山の一番上の数
    v[n] = INF;
    rep(i, n) {
        // vの中でa[i]未満のものの最大値の位置posを二分探索で高速に求める
        auto pos0 = lower_bound(all(v), a[i]);  // vの中でa[i]以上の値が現れる最初の位置のイテレータ
        pos0--;  // vの中でa[i]未満の値が現れる最後の位置のイテレータ
        auto pos = pos0 - v.begin();
        v[pos] = a[i];  // pos番目の山にa[i]を置く
    }

    ll ans = 0;
    rep(i, n) {
        if(v[i] > 0) {
            ans++;
        }
    }

    out(ans);
    re0;
}