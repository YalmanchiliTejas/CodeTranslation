#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <cassert>
#include <iterator>
using namespace std;
using VI = vector<long>;
constexpr long MOD = 998244353;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    
    int i = 0;
    while (1) {
        if (y * i + z * (i + 1) <= x) {
            i++;
        } else {
            break;
        }
    }
    cout << i - 1 << endl;
}
