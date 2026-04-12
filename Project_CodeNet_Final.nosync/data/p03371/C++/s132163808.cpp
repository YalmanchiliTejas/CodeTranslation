#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll a = 0, b = 0, c = 0, x = 0, y = 0;
    cin >> a >> b >> c >> x >> y;
    if (x == y) {
        cout << min(a+b, c*2) * x << endl;
    }
    else if (x < y) {
        cout << min(a+b, c*2) * x + min(b, c*2) * (y-x) << endl;
    }
    else {
        cout << min(a+b, c*2) * y + min(a, c*2) * (x-y) << endl;
    }
    return 0;
}
