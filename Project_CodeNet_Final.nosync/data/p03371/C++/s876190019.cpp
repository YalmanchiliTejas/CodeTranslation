#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 100000000;

int main() {
    int A, B, C, X, Y;
    ll ans = 0;
    cin >> A >> B >> C >> X >> Y;

    int m = min(X, Y); 
    
    if ((A+B) * m < 2 * C * m) {
        ans += (A+B) * m;
    } else {
        ans += 2 * C * m;
    }

    X -= m;
    Y -= m;
    
    if (X > 0) {
        if (A*X < 2 * C * X) {
            ans += A*X;
        } else {
            ans += 2 * C * X;
        }
    }

    if (Y > 0) {
        if (B*Y < 2 * C * Y) {
            ans += B*Y;
        } else {
            ans += 2 * C * Y;
        }
    }

    cout << ans << endl;
}
