#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;
    vector<ll> nums(N);
    REP(i, N) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    ll ans = 0;
    ll sum = nums[N - 1];
    for (ll i = N - 2; i >= 0; --i) {
        ans += (nums[i] * sum) % MOD;
        ans %= MOD;
        sum += nums[i];
        sum %= MOD;
    }
    PR(ans);

    return 0;
}