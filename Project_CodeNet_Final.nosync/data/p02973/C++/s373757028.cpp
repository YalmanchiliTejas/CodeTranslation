#include <algorithm>
#include <array>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;


int main() {
    cout << setprecision(30);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    vl a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 1;
    set<pll> kek;

    for (ll i = 0; i < n; ++i) {
        auto it = kek.lower_bound({a[i], 0});
        if (it == kek.end()) {
            kek.insert({a[i], 1});
            continue;
        }
        pll lol = {a[i], it->second + 1};
        ans = max(ans, lol.second);
        kek.insert(lol);
        auto ti = kek.find(lol);
        while (ti != kek.begin()) {
            if (prev(ti)->second <= lol.second) {
                kek.erase(prev(ti));
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
