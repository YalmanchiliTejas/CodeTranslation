#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    int n;
    cin >> n;

    vector<ll> s(n);
    for (auto &s_i : s) cin >> s_i;

    ll max_score = 0;
    vector<int> visited(n);
    for (int c = 1; c <= n - 1; ++c) {
        ll sum = 0;

        for (int k = 0; (k + 1) * c < n - 1; ++k) {
            if (k * c == n - 1 - k * c) break;
            if (visited[k * c] == c or visited[n - 1 - k * c] == c)
                break;
            visited[k * c] = visited[n - 1 - k * c] = c;

            sum += (s[k * c] + s[n - 1 - k * c]);
            max_score = max(max_score, sum);
        }
    }

    cout << max_score << endl;

    return 0;
}
