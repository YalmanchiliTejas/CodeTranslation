#include<iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    if ((100 * r + 10 * g + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
