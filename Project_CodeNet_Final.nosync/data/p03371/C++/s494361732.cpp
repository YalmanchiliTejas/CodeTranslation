#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    long long int A, B, C, X, Y, P1, P2, P3;
    cin >> A >> B >> C >> X >> Y;

    P1 = C * max(X, Y) * 2;
    P2 = A * X + B * Y;

    if (X >= Y) {
        P3 = C * Y * 2 + A * (X - Y);
    }
    else {
        P3 = C * X * 2 + B * (Y - X);
    }

    cout << min(min(P1, P2), P3);

}

