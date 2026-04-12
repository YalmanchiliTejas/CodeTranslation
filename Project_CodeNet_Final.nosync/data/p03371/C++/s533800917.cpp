#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {        
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b >= 2 * c) {
        int z = min(x, y);
        x -= z;
        y -= z;
        cout << min(z * 2 * c + x * a + b * y, max(x, y) * c * 2 + z * 2 * c) << endl;
    } else {
        cout << a * x + b * y << endl;
    }
}
