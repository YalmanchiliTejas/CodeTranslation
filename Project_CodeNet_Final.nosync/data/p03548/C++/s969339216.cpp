#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;
    int count = 1;
    int buf = y + 2*z;
    while ((buf += y+z) <= x) {
        count++;
    }
    cout << count << endl;
    return 0;
}
