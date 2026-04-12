#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) { cin >> x; }
    sort(a.begin(), a.end());

    auto dsum = [&](auto it1, auto it2) {
        vector<int> b(n);
        for (int i = 1; i < n - 1; i++) {
            b[i] = (i % 2 == 0) ? *it1++ : *it2++;
        }
        b[0] = *it1;
        b[n - 1] = *it2;
        int64_t s = 0;
        for (int i = 1; i < n; i++) {
            s += abs(b[i] - b[i - 1]);
        }
        return s;
    };

    cout << max(dsum(a.begin(), a.rbegin()), dsum(a.rbegin(), a.begin())) << '\n';
}
