#include "bits/stdc++.h"

using namespace std;

void Main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    X -= Z;
    int ans = 0;
    while (X > 0) {
        if (X >= Y + Z) {
            X -= Y + Z;
            ++ans;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
