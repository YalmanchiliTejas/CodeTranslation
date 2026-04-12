#include "bits/stdc++.h"
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int figure = 0;
    while(X >= Y * figure + Z * (figure + 1)){
        figure++;
    }
    figure--;

    cout << figure << endl;
}