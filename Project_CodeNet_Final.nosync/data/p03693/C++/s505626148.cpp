#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int r,g,b;
    int a;
    cin >> r >> g >> b;
    if((g * 10 + b) % 4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}
