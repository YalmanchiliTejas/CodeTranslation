#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A >= 2 * C && B >= 2 * C){
        ans = max(X, Y) * 2 * C;
    }
    else if (A >= 2 * C){
        ans = X * 2 * C;
        ans += max(0, Y - X) * B;
    }
    else if (B >= 2 * C){
        ans = Y * 2 * C;
        ans += max(0, X - Y) * A;
    }
    else if (A + B >= 2 * C){
        if (X >= Y){
            ans = Y * 2 * C;
            ans += (X - Y) * A;
        }
        else {
            ans = X * 2 * C;
            ans += (Y - X) * B;
        }
    }
    else {
        ans = X * A + Y * B;
    }
    cout << ans << endl;
}
