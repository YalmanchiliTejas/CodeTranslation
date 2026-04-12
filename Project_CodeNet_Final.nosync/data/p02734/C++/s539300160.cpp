#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    const size_t M = 998244353;
    size_t N, S;
    cin >> N >> S;
    vector<size_t> a(N);
    for (auto& x : a) {
        cin >> x;
    }

    size_t res = 0;
    vector<size_t> dp(S + 1, 0);
    for (size_t i = 0; i < N; ++i) {
        dp[0] += 1;
        for (int s = S; s >= 0; --s) {
            if (a[i] + s <= S) {
                (dp[a[i] + s] += dp[s]) %= M;
            }
        }
        (res += dp[S]) %= M;
    }
    cout << res;

    return 0;
}