#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int r = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (h >= m) r++;
        m = max(m, h);
    }

    cout << r << endl;

    return 0;
}