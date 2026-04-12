#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int x, y, z, one;
    cin >> x >> y >> z;
    one = y + z;
    x -= z;
    cout << x / one << endl;
}