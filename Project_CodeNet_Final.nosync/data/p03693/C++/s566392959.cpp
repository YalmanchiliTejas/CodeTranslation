#include <iostream>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int num = r*100 + g*10 + b;
    if (num & 0x3) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}