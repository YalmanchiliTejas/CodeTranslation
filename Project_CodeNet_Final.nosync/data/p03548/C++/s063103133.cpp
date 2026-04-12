#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    int X, Y, Z;
    cin >> X >> Y >> Z;

    int count = 0;
    X -= Z;
    while (Y + Z <= X) {
        X -= Y + Z;
        count++;
    }

    cout << count << endl;

    return 0;
}