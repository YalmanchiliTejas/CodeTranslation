#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int X;
    cin >> X;

    if (X == 7 || X == 5 || X == 3) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }

    return 0;
}