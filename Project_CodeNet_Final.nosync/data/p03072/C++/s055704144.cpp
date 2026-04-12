#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> h(n);
    rep (i, n) cin >> h[i];

    int ans = 1, macs = h[0];
    range (i, 1, n) {
        if ( macs <= h[i] ) {
            ans++;
            macs = h[i];
        }
    }

    cout << ans << endl;

    return 0;
}