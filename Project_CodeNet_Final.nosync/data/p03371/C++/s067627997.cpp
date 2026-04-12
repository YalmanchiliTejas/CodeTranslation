#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B <= 2 * C) {
        cout << A * X + B * Y << endl;
        return 0;
    }
    if (A >= 2 * C && X >= Y) {
        cout << 2 * C * X << endl;
        return 0;
    }
    if (B >= 2 * C && X <= Y) {
        cout << 2 * C * Y << endl;
        return 0;
    }
    if (X >= Y) {
        cout << 2 * C * Y + A * (X - Y) << endl;
    }
    else {
        cout << 2 * C * X + B * (Y - X) << endl;
    }


}
