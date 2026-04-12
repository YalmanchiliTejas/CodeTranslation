//
// Created by moono on 2018/10/27.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main() {
    int x, y, z;
    cin >> x >> y >> z;

    x -= z;
    int n = x / (y+z);

    cout << n << endl;
    return 0;
}