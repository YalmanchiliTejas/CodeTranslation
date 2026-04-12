#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll zero = 0;
    for(ll i = k + 1; i <= n; i++){
        ans += (n / i) * (i - k);
        ans += max(zero, n - ((n / i) * i - 1 + k));
    }
    if(k == 0) ans -= n;
    cout << ans << endl;
}