#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int a = 0, b = 0, c, sum = A*X + B*Y;
    for(int i = 0; i <= max(X, Y) * 2; i++){
        a = 0;
        b = 0;
        if(i % 2 != 0) continue;
        c = C * i;
        if(i/2 < X) a = (X - i / 2) * A;
        if(i/2 < Y) b = (Y - i / 2) * B;
        sum = min(sum, a + b + c);
    }
    cout << sum << endl;
}