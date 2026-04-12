#include <iostream>

using namespace std;

int main(void) {
    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}