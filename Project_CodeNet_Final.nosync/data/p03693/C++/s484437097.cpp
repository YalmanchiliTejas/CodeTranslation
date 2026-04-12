#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,g,b,x;
    cin >> r >> g >> b;
    x = r*100 + g*10 + b;
    if (x%4) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}