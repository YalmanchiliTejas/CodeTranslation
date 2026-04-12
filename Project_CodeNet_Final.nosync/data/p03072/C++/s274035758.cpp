#include "bits/stdc++.h"
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int maxx = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] >= maxx) {
            maxx = h[i];
            ++ans;
        }
    }
    cout << ans;
    return 0;
}