#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int r, g, b;
    
    cin >> r >> g >> b;
    
    int res = r * 100 + g * 10 + b;
    if (res % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}