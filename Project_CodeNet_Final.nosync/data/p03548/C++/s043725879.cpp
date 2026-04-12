#include "bits/stdc++.h"
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int res = 0;
    for (int i = 1; ; i++) {
        int need = i * y + (i + 1) * z;
        if (need > x) break;
        res = i;
    }
    cout << res << endl;
}