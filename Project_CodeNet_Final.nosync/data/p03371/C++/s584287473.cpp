#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 2*5000*100000;
    rep(i, 2*max(X, Y)) {
        int tmp = i*2*C + max(0, X - i)*A + max(0, Y - i)*B;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}