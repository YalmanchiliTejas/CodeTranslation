#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = -1;
    for(int c = 0; c <= 2 * max(X, Y); c += 2) {
        ll cost = C * c + A * max(0, (X - c / 2)) + B * max(0, (Y - c / 2));
        if(ans == -1) {
            ans = cost;
        } else {
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
    return 0;
}