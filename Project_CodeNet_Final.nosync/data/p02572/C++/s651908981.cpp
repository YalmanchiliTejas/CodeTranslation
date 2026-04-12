#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n+1, 0LL);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<ll> b(a);
    for(int i=1;i<=n;++i) {
        b[i] += b[i-1];
        b[i] %= MOD;
    }

    ll ans = 0LL;
    for(int i=1;i<n;++i) {
        ans += (a[i] * (b[n] - b[i] + MOD) % MOD) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
