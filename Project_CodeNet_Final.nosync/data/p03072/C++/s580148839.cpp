#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        bool f = true;
        for(int j = 0; j < i; ++j) {
            f &= h[j] <= h[i];
        }
        ans += f;
    }
    cout << ans << endl;
}