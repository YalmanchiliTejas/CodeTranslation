#include <bits/stdc++.h>

using namespace std;

long long prime = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> as(n);
    for (auto& a : as) {
        cin >> a;
    }
    vector<vector<long long>> count(n + 1, vector<long long>(s + 1, 0));
    count[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        count[i + 1][0] = 1;
        for (int t = 0; t <= s; ++t) {
            count[i + 1][t] += count[i][t];
            if (t >= as[i]) {
                count[i + 1][t] += count[i][t - as[i]];
            }
            count[i + 1][t] %= prime;
        }
    }
    long long total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        total_sum += count[i][s];
    }
    total_sum %= prime;
    cout << total_sum << endl;
    return 0;
}
