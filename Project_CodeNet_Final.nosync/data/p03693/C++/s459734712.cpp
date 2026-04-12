#include <iostream>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int gb = g * 10 + b;
    if (gb % 4 == 0)    cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}