#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int r, g, b;

    cin >> r >> g >> b;
    int n = 100 * r + 10 * g + b;

    if (n % 4 == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
