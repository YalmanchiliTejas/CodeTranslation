#include <iostream>
using namespace std;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = 2000000000;
    for (int i = 0; i <= 100000; i++) {
        int cost = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}