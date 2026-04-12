#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

int main(void) {
    int r, g, b;
    cin >> r >> g >> b;

    int rgb = 100 * r + 10 * g + b;
    cout << (rgb % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
