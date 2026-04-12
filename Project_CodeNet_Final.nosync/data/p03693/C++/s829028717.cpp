#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, g, b;
    cin >> r >> g >> b;
    r = r * 100;
    g = g * 10;
    int result = r + g + b;
    if (result % 4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}