#include<bits/stdc++.h>
using namespace std;

signed main() {

    int n, h[32], ans = 1;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) scanf("%d", &h[i]);
    for ( int i = 1; i < n; i++ ) {
        bool flg = true;
        for ( int j = 0; j < i; j++ ) {
            flg &= h[j] <= h[i];
        }
        ans += flg;
    }
    cout << ans << endl;

    return 0;
}