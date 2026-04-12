#include"bits/stdc++.h"
using namespace std;

int main() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;
    if (X % (Y + Z) >= Z) {
        cout << X / (Y + Z) << endl;
    } else {
        cout << X / (Y + Z) - 1 << endl;
    }
}