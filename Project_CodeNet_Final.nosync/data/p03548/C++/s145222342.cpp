#include <iostream>
using namespace std;
typedef long long ll;
int main (void) {
    ll X;
    ll Y;
    ll Z;
    ll ans = 0;

    cin >> X >> Y >> Z;

    for (ll i = 1; i <= X; i++) {
        if (Y * i + Z * (i + 1) <= X) ans++;
    }

    cout << ans << endl;

    return 0;
}