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
    ll m = n/2;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(rall(a));

    ll ans;
    if(n%2 == 1) {
        ll ans1 = 0;
        exrep(i, 0, m-2) {
            ans1 += 2*a[i];
        }
        exrep(i, m-1, m) {
            ans1 += a[i];
        }
        exrep(i, m+1, n-1) {
            ans1 -= 2*a[i];
        }
        ll ans2 = 0;
        exrep(i, 0, m-1) {
            ans2 += 2*a[i];
        }
        exrep(i, m, m+1) {
            ans2 -= a[i];
        }
        exrep(i, m+2, n-1) {
            ans2 -= 2*a[i];
        }
        ans = max(ans1, ans2);
    }
    else {
        ans = 0;
        exrep(i, 0, m-2) {
            ans += 2*a[i];
        }
        ans += a[m-1];
        ans -= a[m];
        exrep(i, m+1, n-1) {
            ans -= 2*a[i];
        }
    }
    
    out(ans);
    re0;
}