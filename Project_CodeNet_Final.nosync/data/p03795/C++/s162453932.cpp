//
// Created by Leo Chen on 2019-08-28.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = n*800;
    int y = n/15;
    y = y * 200;
    cout << x - y << endl;
    return 0;
}
