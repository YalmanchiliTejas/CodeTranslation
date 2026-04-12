#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;

    if (A+B >= C*2){
        if (X < Y){
            ans += X * C * 2;
            if (B < C * 2){
                ans += B * (Y - X);
            } else {
                ans += 2 * C * (Y - X);
            }
        }
        if (X >= Y){
            ans += Y * C * 2;
            if (A < C * 2){
                ans += A * (X - Y);
            } else {
                ans += 2 * C * (X - Y);
            }
        }

    } else {
        if (X < Y){
            ans += X * A;
            if (B < C * 2){
                ans += B * Y;
            } else {
                ans += 2 * C * Y;
                ans -= A * X;
            }
        }
        if (X >= Y){
            ans += Y * B;
            if (A < C * 2){
                ans += A * X;
            } else {
                ans += 2 * C * X;
                ans -= B * Y;
            }
        }
    }

    cout << ans << endl;
}