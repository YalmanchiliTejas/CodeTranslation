#include <iostream>
#include <limits>

using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = numeric_limits<ll>::max();
    for(ll nc = 0; nc <= max(2 * x, 2 *y); ++nc){
        const ll na = max(0LL, (2 * x - nc + 1) / 2);
        const ll nb = max(0LL, (2 * y - nc + 1) / 2);
        ans = min(
            ans,
            a * na + b * nb + c * nc
        );
    }
    cout << ans << endl;
    return 0;
}
