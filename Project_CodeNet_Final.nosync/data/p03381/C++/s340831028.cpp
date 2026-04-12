#include <bits/stdc++.h>
#define int long long
#define pq priority_queue

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nos(n);
    for (int i = 0; i < n; i++) {
        cin >> nos[i];
    }
    vector<int> sorted_v = nos;
    sort(sorted_v.begin(), sorted_v.end());
    int low_med = sorted_v[n / 2 - 1];
    int high_med = sorted_v[n / 2];
    for (int i = 0; i < n; i++) {
        if (nos[i] <= low_med) {
            cout << high_med << '\n';
        } else {
            cout << low_med << '\n';
        }
    }
}