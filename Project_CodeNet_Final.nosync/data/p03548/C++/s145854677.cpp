#include <iostream>

using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X -= Z;
    cout << int(X / (Y + Z)) << endl;
}