#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, g, b;
    cin >> r >> g >> b;

    int k = 100 * r + 10 * g + b;
    cout << (k % 4 ? "NO" : "YES") << endl;
}
