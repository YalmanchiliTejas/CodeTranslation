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
    int r, g, b;
    cin >> r >> g >> b;
    if ((g * 10 + b) % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


