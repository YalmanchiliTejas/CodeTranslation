#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
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
    }

    deque<ll> d;
    rep(i, n) {
        ll p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(p == 0) {
            d.push_front(a[i]);
        }
        else {
            d[p-1] = a[i];
        }
    }

    out(d.size());
    re0;
}