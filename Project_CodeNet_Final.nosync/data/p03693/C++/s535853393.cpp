#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int a = r * 100 + g * 10 + b;


    std::cout << (a % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}