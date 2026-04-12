#include <cstdio>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    int r, g, b,x;
    cin >> r >> g >> b;
    x = 100 * r + 10 * g + b;
    if (x % 4 == 0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}