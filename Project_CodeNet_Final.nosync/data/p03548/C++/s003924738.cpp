#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    cout << (x - z) / (y + z) << endl;

    return 0;
}