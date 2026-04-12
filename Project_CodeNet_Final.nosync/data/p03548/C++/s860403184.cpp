#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    x -= z;
    cout << max(0, x / (y + z)) << endl;
}
