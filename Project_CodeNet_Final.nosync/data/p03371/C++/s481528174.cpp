#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cstdlib>  // abs() for integer
#include <math.h>     // math.h をインクルードする！
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c) {
        cout << a * x + b * y << endl;
        return 0;
    }
    else {
        int money_1 = c * 2 * min(x, y);
        if (x == y) {
            cout << money_1 << endl;
            return 0;
        }

        else if (x > y && a < 2 * c) {
            cout << money_1 + a * (x - y) << endl;
            return 0;
        }

        else if(x < y && b < 2 * c) {
            cout << money_1 + b * (y - x) << endl;
            return 0;
        }

        else {
            cout << money_1 + c * 2 * abs(x - y) << endl;
            return 0;
        }
    }
    // cout << x << ' ' << y << endl;
}