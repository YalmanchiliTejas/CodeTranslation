#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n; int x, m; cin >> n >> x >> m;
    vector<int> ans(m+5);
    map<int, int> mp;
    mp[x] = 1;
    int cycle = 0;
    int start = -1;
    ans[1] = x;
    for(int i = 2; i <= m + 5; ++i) {
        x = (1ll * x * x) % m;
        if (mp[x] != 0) {
            start = mp[x];
            cycle = i - mp[x];
            break;
        }
        ans[i] = x;
        mp[x] = i;
    }
    ll cyclesum = 0;
    for(int i = start; i < start + cycle; ++i) cyclesum += ans[i];
    vector<ll> pref(m+5);
    range(i, m) pref[i+1] = pref[i] + ans[i+1];
    if (n < start) {
        cout << pref[n] << "\n";
        return;
    }
    ll k = (n - start + 1) / cycle;
    ll answ = k * cyclesum;
    ll e = (n -  start + 1) % cycle;
    answ += pref[start + e - 1];
    cout << answ << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}