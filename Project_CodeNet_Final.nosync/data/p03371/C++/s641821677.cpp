#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,C,X,Y;
    int N,n;
    int ans;
    cin >> A >> B >> C >> X >> Y;
    N = max(X,Y);
    n = min(X,Y);
    if((A+B) > (C*2)) {
        ans = n * C * 2;
        if(X > Y) {
            if(A > (2*C)) { 
                ans += (X-Y) * 2 * C;
            } else {
                ans += (X-Y) * A;
            }
        } else {
            if(B > (2*C)) { 
                ans += (Y-X) * 2 * C;
            } else {
                ans += (Y-X) * B;
            }
        }
    } else {
        ans = X*A + Y * B;
    }
    cout << ans << endl;    
    return 0;
}
