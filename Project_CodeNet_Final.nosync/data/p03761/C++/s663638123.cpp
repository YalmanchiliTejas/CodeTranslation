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

    vl v(26, INF);
    rep(i, n) {
        string s;
        cin >> s;
        vl w(26);
        rep(j, s.size()) {
            w[s[j] - 'a']++;
        }
        rep(j, 26) {
            chmin(v[j], w[j]);
        }
    }

    rep(i, 26) {
        char c = 'a' + i;
        rep(j, v[i]) {
            cout << c;
        }
    }
    
    cout << endl;
    re0;
}