#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define int long long
using namespace std;

signed main() {
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
