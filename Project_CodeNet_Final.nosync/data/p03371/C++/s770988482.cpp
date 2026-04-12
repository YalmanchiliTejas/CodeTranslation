#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    int hoge = (A+B < 2*C) ? A+B : 2*C;
    while(X != 0 && Y != 0) {
        X--; Y--;
        ans += hoge;
    }
    if (Y && B < 2*C) ans += Y*B;
    else if (X && A < 2*C) ans += X*A;
    else {
        hoge = X > Y ?  X : Y;
        ans += hoge*2*C;
    }
    cout << ans << endl;
    return 0;
}