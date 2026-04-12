#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> h[i], ans += h[i] >= mx, mx = max(mx, h[i]);
    cout << ans << endl;
}