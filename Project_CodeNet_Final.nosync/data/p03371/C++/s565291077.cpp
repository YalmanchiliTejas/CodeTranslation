#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;
int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = LLONG_MAX;
    for (int i = 0; i <= 2*max(X, Y); i+=2) {
        ll tmp = i*C;
        tmp += max((ll)0, X-i/2)*A + max((ll)0, Y-i/2)*B;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}