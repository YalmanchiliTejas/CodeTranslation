#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {

    size_t N;
    cin >> N;
    vector<long long> a(N + 1);
    vector<long long> dp(N + 1, 0);
    vector<long long> prev(N + 1, 0);
    for (size_t i = 1; i <= N; ++i) cin >> a[i];
    prev[1] = a[1];
    for (size_t i = 3; i <= N; i += 2) prev[i] = a[i] + prev[i - 2];

    for (size_t i = 2; i <= N; ++i) {
        if ((i & 1) == 0) {
            dp[i] = max(prev[i - 1], dp[i - 2] + a[i]);
        } else {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
    }
    
    cout << dp[N];
    return 0;
}