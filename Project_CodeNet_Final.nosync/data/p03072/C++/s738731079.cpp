#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int maxi = -1; int ans = 0;
    for (int i = 0; i < n; i++) {
        if (maxi <= h[i]) {
            ans++; maxi = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}