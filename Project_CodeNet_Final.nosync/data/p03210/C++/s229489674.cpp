#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    switch (x) {
        case 3:  // fall through
        case 5:  // fall through
        case 7:
            cout << "YES\n";
            break;
        default:
            cout << "NO\n";
            break;
    }
}
