#include <bits/stdc++.h>

using namespace std;

int r, g, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> r >> g >> b;

    if ((g + g + b) % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
