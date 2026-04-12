#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;
    int maxLoop = 1 + max(X, Y);
    int attain = 0;
    for (int i = 1; i < maxLoop; ++i) {
        int temp = C * 2 * i + A * max(X - i, 0) + B * max(Y - i, 0);
        if (temp < ans) {
            ans = temp;
            attain = i;
        }
    }

    cout << ans << endl;
    return 0;
}
