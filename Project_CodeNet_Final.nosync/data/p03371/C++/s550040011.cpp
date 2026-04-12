#include <bits/stdc++.h>
using namespace std;

int main()
{
    const static int64_t zero64 = 0;
    int64_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A > B) {
        swap(A, B);
        swap(X, Y);
    }
    int64_t min_cost = A * X + B * Y;
    if (2 * C <= A)
        min_cost = 2 * C * max(X, Y);
    else if (2 * C <= B)
        min_cost = 2 * C * Y + A * max(zero64, X - Y);
    else if (2 * C <= A + B) {
        min_cost = 2 * C * min(X, Y);
        min_cost += A * max(zero64, X - Y) + B * max(zero64, Y - X);
    }
    cout << min_cost << endl;
}
