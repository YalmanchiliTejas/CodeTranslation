#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    int n;  cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());
    if (n % 2) {
        ll ans = 0;
        for (int i = 0; i <= n/2 - 2; i++)
            ans += 2*a[i];
        ans += a[n/2-1] + a[n/2];
        for (int i = n/2+1; i < n; i++)
            ans -= 2 * a[i];
        ll tmp = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i <= n/2 - 2; i++)
            tmp -= 2*a[i];
        tmp -= a[n/2-1] + a[n/2];
        for (int i = n/2+1; i < n; i++)
            tmp += 2 * a[i];
        ans = max(ans, tmp);
        cout << ans << endl;
        return 0;
    }
    else {
        ll ans = 0;
        for (int i = 0; i < n/2-1; i++)
            ans += 2*a[i];
        ans += a[n/2-1];
        ans -= a[n/2];
        for (int i = n/2+1; i < n; i++)
            ans -= 2*a[i];
        cout << ans << endl;
        return 0;
    }
}