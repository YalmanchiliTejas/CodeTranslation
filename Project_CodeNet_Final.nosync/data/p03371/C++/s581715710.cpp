#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;
    for (int i = 1; i <= max(X, Y); ++i) {
        int temp = A * max(0, X - i) + B * max(0, Y - i) + C * 2 * i;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
