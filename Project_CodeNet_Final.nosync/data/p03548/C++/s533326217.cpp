#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    X = max(X - Z, 0);

    int n = X / (Y + Z);
    cout << n << endl;

    return 0;
}