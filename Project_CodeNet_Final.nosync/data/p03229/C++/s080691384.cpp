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
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(rall(a));

    ll m = n/2;
    if(n%2 == 0) {  // nが偶数のとき
        // p1 < p2 > p3 < … のパターンでも
        // p1 > p2 < p3 < … のパターンでも結果は同じ
        ll ans = 0;
        rep(i, n) {
            if(i < m-1) {
                ans += 2*a[i];
            }
            else if(i == m-1) {
                ans += a[i];
            }
            else if(i == m) {
                ans -= a[i];
            }
            else {
                ans -= 2*a[i];
            }
        }
        out(ans);
    }
    else {  // nが奇数のとき
        // p1 > p2 < p3 < … のパターン
        ll ans1 = 0;
        rep(i, n) {
            if(i < m-1) {
                ans1 += 2*a[i];
            }
            else if(i <= m) {
                ans1 += a[i];
            }
            else {
                ans1 -= 2*a[i];
            }
        }
        // p1 < p2 > p3 < … のパターン
        ll ans2 = 0;
        rep(i, n) {
            if(i < m) {
                ans2 += 2*a[i];
            }
            else if(i <= m+1) {
                ans2 -= a[i];
            }
            else {
                ans2 -= 2*a[i];
            }
        }
        out(max(ans1, ans2));
    }

    re0;
}