#include <bits/stdc++.h>
using namespace std;
int X, Y, Z;
int main() {
    cin >> X >> Y >> Z;
    int num = 0;
    num = X / (Y+Z);
    int r = X % (Y+Z);
    if(r >= Z) {
        cout << num << endl;
    }else {
        cout << num-1 << endl;
    }
}