#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int mx = 0;
    rep(i, N) {
        int H;
        cin >> H;
        mx = max(mx, H);
        if (H >= mx) ans += 1;
    }
    cout << ans << endl;
    return 0;
}