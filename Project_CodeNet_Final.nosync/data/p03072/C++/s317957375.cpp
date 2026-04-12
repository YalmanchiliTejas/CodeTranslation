#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, h, ans, r;
    cin >> n;
    
    for ( int i = 0; i < n; i++ ) {
        cin >> h;
        if ( i == 0 ) {
            ans = 1;
            r = h;
        } else {
            if ( r <= h ) {
                r = h;
                ans++;
            } 
        }
    }
    
    cout << ans << endl;
    return (0);
}