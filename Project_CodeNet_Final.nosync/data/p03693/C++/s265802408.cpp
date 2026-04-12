#include <iostream>
#include <string>
#include <vector>
typedef unsigned int UINT;
using namespace std;
int main(void) {
    int r, g, b;
    cin >> r >> g >> b;
    int sum = g * 10 + b;
    if (sum % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}