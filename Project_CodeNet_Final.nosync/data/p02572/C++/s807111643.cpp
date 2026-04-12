#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

#define forn(n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef unsigned int uint;
typedef long double ld;

const int INT_INF=1e9;
const ll LONG_INF=1e18;
const double pi = acos(-1);
const int MAXN = 1e6;
const int MAXM = 1e6;
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    ll sum = 0;
    vector<ll> inp(n);
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
        sum += inp[i];
    }
    sum %= MOD;
    for (int i = 0; i < n; ++i) {
        sum = (sum - inp[i] + MOD) % MOD;
        ans = (ans + inp[i] * sum) % MOD;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(9);
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    solve();

#ifdef LOCAL
    cout << "Time:\n";
    cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << '\n';
#endif

}
