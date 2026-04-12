#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    cout << ((g * 2 + b) % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}