#include <iostream>
using namespace std;

int main() {
    char x;
    cin >> x;
    switch (x - '0') {
        case 3:
        case 5:
        case 7:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
    }
}