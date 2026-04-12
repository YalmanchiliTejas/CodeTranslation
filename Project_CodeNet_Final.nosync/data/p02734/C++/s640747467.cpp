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
constexpr ll MOD = 998244353;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,s;
    cin >> n >> s;
    vector<int> a(n+1, 0);
    for(int i=0;i<n;++i) {
        cin >> a[i+1];
    }

    ll ans = 0LL;
    vector<vector<ll>> cnt(n+1, vector<ll>(s+1, 0));
    for(int i=1;i<=n;++i) {
        if(a[i] < s) {
            ans += (cnt[i-1][s-a[i]] * ll(n-i+1)) % MOD;
            ans %= MOD;
        } else if(a[i] == s) {
            ans += (ll(i) * ll(n-i+1)) % MOD;
            ans %= MOD;
        }

        if(a[i] <= s) {
            cnt[i][a[i]] += i;
            cnt[i][a[i]] %= MOD;
        }
        for(int j=0;j<=s;++j) {
            cnt[i][j] += cnt[i-1][j];
            cnt[i][j] %= MOD;
            if(j+a[i] <= s) {
                cnt[i][j+a[i]] += cnt[i-1][j];
                cnt[i][j+a[i]] %= MOD;
            }
        }
    }
    
    cout << ans << endl;
}
