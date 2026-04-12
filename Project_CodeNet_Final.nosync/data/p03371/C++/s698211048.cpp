#include <iostream>
using namespace std;
const int INF = 1000000000;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = INF;
    for (int i = 0; i <= 100000; i++) {
        int cost = (2 * C * i) + max(0, X-i) * A + max(0, Y-i) * B;
        ans = min(ans, cost); 
    }
    cout << ans << endl;
}