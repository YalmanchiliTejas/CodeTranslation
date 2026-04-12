#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int x = X;
    int y = Y;
    int z = 0;
    int ans = A * x + B * y;
    while (x > 0 || y > 0) {
        z += 2;
        x = max(x - 1, 0);
        y = max(y - 1, 0);
        ans = min(ans, A * x + B * y + C * z);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
