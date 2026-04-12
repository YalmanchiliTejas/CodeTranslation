#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;
    for (int i = 50000; i >= 0; i--) {
        if (X >= Y * i + Z * (i + 1)) {
            cout << i << endl;
            return 0;
        }
    }
}