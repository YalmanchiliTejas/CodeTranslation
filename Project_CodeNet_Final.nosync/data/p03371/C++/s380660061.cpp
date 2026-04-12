// Half and Half

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    // aピザ: a円、abピザ: c円
    // aピザをx枚、bピザをy枚用意する必要がある

    // xとyの最小値 =: minまでは
    // aピザとbピザをmin枚買う or abピザを2 * min枚買う　の最小値    ----(1)
    // aピザが残りx - min枚( > 0)とすると、
    // aピザをx - min枚買う or abピザを2 * (x - min)枚買う　の最小値 ----(2)
    // (1) + (2) が求めるべき答え

    int res = 0;
    int min_mai = min(x, y);
    x -= min_mai;
    y -= min_mai;

    res += min(a*min_mai + b*min_mai, c*2*min_mai);

    if (x > 0) {
        res += min(a*x, c*2*x);
    }
    if (y > 0) {
        res += min(b*y, c*2*y);
    }

    cout << res << endl;

    return 0;
}
