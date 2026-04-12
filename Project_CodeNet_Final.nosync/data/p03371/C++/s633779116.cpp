#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int cross = min(x, y);
    int na = 0, nb = 0,nc = 0;
    if (a + b <= 2 * c) {
        na = x;
        nb = y;
    }
    else {
        //かぶってるところはABを買う
        nc = 2 * cross;
        // 残りは、基本的にAを買う。ただし、ABピザがやたら安ければ、そっちを買う。
        if (a <= 2 * c) {
            na += x - cross;
        }
        else {
            nc += 2 * (x - cross);
        }
        if (b <= 2 * c) {
            nb += y - cross;
        }
        else {
            nc += 2*(y - cross);
        }
    }
    int minPrice = a * na + b * nb + c * nc;
    cout << minPrice << endl;

    return 0;
}

