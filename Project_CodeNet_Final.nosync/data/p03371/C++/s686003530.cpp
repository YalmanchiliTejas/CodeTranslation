#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>

using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int x, y; cin >> x >> y;

    long cost = 0;
    if (a + b > 2*c) {
        auto t = min(x, y);
        cost += 2 * c * t;
        x -= t;
        y -= t;
    }
    if (x > 0) {
        if (a > 2*c) {
            cost += 2*c*x;
        } else {
            cost += a*x;
        }
    }
    if (y > 0) {
        if (b > 2*c) {
            cost += 2*c*y;
        } else {
            cost += b*y;
        }
    }
    cout << cost << endl;
    return 0;
}