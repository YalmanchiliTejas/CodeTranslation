#include <bits/stdc++.h>

using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    if ((10 * g + b)%4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}