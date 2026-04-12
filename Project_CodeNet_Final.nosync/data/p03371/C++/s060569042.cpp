#include <iostream>
using namespace std;
const int INF = 1000000000;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = INF;
    for (int i = 0; i <= max(X, Y); i++) {
        int cost = A * max(0, X - i) + B * max(0, Y - i) + 2 * C * i;
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}