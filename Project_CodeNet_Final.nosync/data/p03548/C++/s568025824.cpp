#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z, k = 1;
    cin >> x >> y >> z;
    x = x - z * 2 - y;
    k = k + x / (y + z);
    cout << k;
}