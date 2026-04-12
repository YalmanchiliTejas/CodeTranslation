#include <iostream>
using namespace std;

int main() {
    int r, g, h, i;
    cin >> r >> g >> h;

    i = r * 100 + g* 10 + h;
    
    if (i % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}