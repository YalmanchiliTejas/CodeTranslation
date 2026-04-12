#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int cost1 = A * X + B * Y;
    int cost2 = 2 * X * C;
    int cost3 = 2 * Y * C;
    
    if (X < Y) cost2 += (Y - X) * B;
    if (X > Y) cost3 += (X - Y) * A;
    int mi = cost1;
    if (mi > cost2) mi = cost2;
    if (mi > cost3) mi = cost3;
    cout << mi << endl;
}