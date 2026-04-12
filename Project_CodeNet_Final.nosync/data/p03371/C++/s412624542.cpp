#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int k = max(X,Y);
    int ans = 2000000000;
    for(int ab = 0; ab <= k; ab++) {
        int a = max(0, X-ab);
        int b = max(0, Y-ab);
        ans = min(ans, a*A+b*B+2*ab*C);
    }
    cout << ans << endl;
}
