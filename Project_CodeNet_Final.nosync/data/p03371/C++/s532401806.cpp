#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (X > Y) {
        swap(A, B);
        swap(X, Y);
    }

    cout << X * min(A+B, 2*C) + (Y-X) * min(B, 2*C) << endl;
}