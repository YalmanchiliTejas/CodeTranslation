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

    vvl v(n, vl(26));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            v[i][s[j] - 'a']++;
        }
    }

    vl w(26, 100);
    rep(i, 26) {
        rep(j, n) {
            chmin(w[i], v[j][i]);
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {
        rep(j, w[c - 'a']) {
            cout << c;
        }
    }

    cout << endl;

    /*cout << "\n";
    rep(i, 4) {
        cout << w[i] << " ";
    }*/

    /*cout << "\n";
    rep(i, n) {
        rep(j, 4) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }*/

    re0;
}