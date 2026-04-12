#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    x = 800 * n;
    y = 200 * (n / 15);

    cout << x - y << endl;

    return 0;
}
