#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int gg = n / 15;
    cout << 800 * n - gg * 200 << endl;
    return 0;
}