#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int A, B, C, X, Y;
int main() {
    cin >> A >> B >> C >> X >> Y;
    long long ans = pow(10, 9);

    int maxMix = max(X, Y);
    for(int i = 0; i <= maxMix; i++) {
        long long crr = 2 * C * i + A*max(0, (X-i)) + B*max(0, (Y-i));
        if(crr < ans) ans = crr;
    }
    cout << ans << endl;

    return 0;
}
