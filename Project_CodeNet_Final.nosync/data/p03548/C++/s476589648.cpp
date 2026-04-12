#include <iostream>
using namespace std;

int main() {
    // input
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // solve
    int ans = 0;
    for (int i = 1; i < 100000; ++i) {
        if ((i * Y + Z * (i + 1)) > X) {
            ans = i - 1;
            break;
        }
    }

    // output
    cout << ans << endl;

    return 0;
}
