#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 10;
int r,g,b;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> r >> g >> b;
    int x = 100 * r + 10 * g + b;

    if (x%4 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
