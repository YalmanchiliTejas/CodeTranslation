#include <iostream>

using namespace std;
const int INF = 1001001001;

int main() {
    int a, b, c, X, Y;
    cin >> a >> b >> c >> X >> Y;

    int ans = INF;
    for (int i = 0; i <= 200000; i += 2) {
        int cost = i * c;

        int x = X - i/2;
        int y = Y - i/2;
        cost += max(0, x) * a + max(0, y) * b;

        ans = min(ans, cost);
    }
    cout << ans << endl;
}