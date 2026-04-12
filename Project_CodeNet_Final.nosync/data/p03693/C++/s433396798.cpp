#include <iostream>
#include <string.h>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int main( void ) {

    int r, g, b;
    cin >> r >> g >> b;
    r = r * 100 + g * 10 + b;

    if ( r % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;   
}