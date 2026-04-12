#include <iostream>

using namespace std;

int main() {
    unsigned int x,y,z;
    cin >> x >> y >> z;
    unsigned int num = x / (y+z);
    unsigned int haji = x % (z+y);
    if(haji >= z) {
        cout << num << endl;
    }
    else {
        cout << num - 1 << endl;
    }
    return 0;
}