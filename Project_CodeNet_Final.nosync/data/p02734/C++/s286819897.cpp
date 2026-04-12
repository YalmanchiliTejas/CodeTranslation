#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    vector<ll> dp(K + 1, 0);

    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = K; j - a[i] >= 0; j--) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
        ans += dp[K];
        ans %= MOD;
        dp[0]++;
    }

    cout << ans << endl;
    return 0;
}
