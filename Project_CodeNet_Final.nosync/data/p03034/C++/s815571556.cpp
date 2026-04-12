#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> xs(n);
    for (auto& x : xs) {
        cin >> x;
    }
    long long best = xs[0] + xs[n-1];
    for (int c = 1; 2*c < n-1; ++c) {
        long long current = xs[0] + xs[n-1];
        int i = 0, j = n-1;
        while (true) {
            i += c;
            if (i == j) {
                break;
            }
            j -= c;
            if (i == j || j <= c) {
                break;
            }
            current += xs[i] + xs[j];
            best = max(best, current);
        }
    }
    cout << best << endl;
    return 0;
}
