#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, X, M;
    cin >> N >> X >> M;
    vector<int> seen(M, -1);
    long long ans = 0;
    for (long long i = 0, cur = X; i < N; ++i) {
        if (seen[cur] == -1) {
            seen[cur] = i;
        } else {
            // cycle found
            long long cycle = (i - seen[cur]); // seen[cur] ~ i - 1;
            vector<long long> sum(cycle + 1, 0);
            for (long long i = 1, n = cur; i == 1 || n != cur; ++i, n = (n * n) % M) {
                sum[i] = sum[i - 1] + n;
            }
            long long L = N - i; // i ~ N - 1
            ans += sum[cycle] * (L / cycle) + sum[L % cycle];
            cout << ans << '\n';
            return 0;
        }
        ans += cur;
        cur = (cur * cur) % M;
    }
    cout << ans << '\n';
    return 0;
}