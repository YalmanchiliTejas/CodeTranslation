#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int total = 100 * r + 10 * g + b;

    string res = "NO";
    if (total % 4 == 0) {
        res = "YES";
    }

    cout << res << endl;
}