#include <iostream>


using namespace std;

int main() {
    int r,g,b,rx100,gx10;
    int integer;
    cin >> r >> g >> b;

    rx100 = r * 100;
    gx10 = g * 10;
    
    integer = rx100 + gx10 + b;

    if(integer % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}