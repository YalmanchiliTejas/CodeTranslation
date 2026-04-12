#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ans = 1, highest = h[0];
    for (int i = 1; i < n; ++i) {
        if (h[i] >= highest) {
            highest = h[i];
            ++ans;
        }
    }
    cout << ans;
    return 0;
}

