#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;

    int n = x / (y + z);
    if (z <= x - n * (y + z)) cout << n << endl;
    else cout << n - 1 << endl;

    return 0;
}
 
