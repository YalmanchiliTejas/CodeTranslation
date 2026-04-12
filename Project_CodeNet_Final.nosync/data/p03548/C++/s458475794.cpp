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
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;

}
