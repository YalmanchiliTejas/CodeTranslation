#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int N;
    cin >> N;

    int ma = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;

        ans += (ma <= H);
        ma = max(ma, H);
    }
    cout << ans << endl;
}
