#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int maxv = 0;
    rep(i, n) {
        int h; cin >> h;
        if (maxv <= h) ans++;
        maxv = max(h, maxv);
    }

    cout << ans << endl;
    return 0;
}
