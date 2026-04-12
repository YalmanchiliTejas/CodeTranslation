#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll MAX_N = 1e5;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;

    for (ll b = K + 1; b <= N; b++) {
        ans += N / b * (b - K);
        if (K == 0) {
            ans--;
        }
        ll mod = N % b;
        if (mod >= K) {
            ans += mod - K + 1;
        }
    }

    cout << ans << endl;
    return 0;
}

