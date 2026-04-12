#include "bits/stdc++.h"
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int m = -1;
    for (int i = Z; i <= X; i += (Y + Z)) {
        m++;
    }

    cout << m << endl;
}