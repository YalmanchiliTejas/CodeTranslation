#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int r, g, b;
    cin >> r >> g >> b;
    cout << (!((g * 10 + b) % 4) ? "YES" : "NO") << endl;
}
