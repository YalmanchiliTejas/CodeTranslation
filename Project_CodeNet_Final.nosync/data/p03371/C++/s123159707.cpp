#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll a,b,c,x,y;
cin >> a >> b >> c >> x >> y;
ll costofa = min(a, 2 * c);
ll costofb = min(b, 2 * c);
ll ans = 1e17;
for (ll i = 0; i < 1e5+1;i++){
    ans = min(ans, i * 2 * c + max(0LL, x - i) * a + max(0LL, y - i) * b);
}
cout << ans << endl;
}
