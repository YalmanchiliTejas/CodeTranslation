#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if (C < (A+B)/2) {
        if (X < Y) {
            ans += C*2*X;
            if (B/2 < C) {
                ans += B*(Y - X);
            }
            else {
                ans += C*2*(Y - X);
            }
        }
        else {
            ans += C*2*Y;
            if (A/2 < C) {
                ans += A*(X - Y);
            }
            else {
                ans += C*2*(X - Y);
            }
        }
    }
    else {
        ans = min(A*X + B*Y, min(C*2*X + B*(Y - X), C*2*Y + A*(X - Y)));
    }   

    cout << ans << endl;

    return 0;
}
