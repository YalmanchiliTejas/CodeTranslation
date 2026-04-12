#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll mod = 1e9+7, *s = new ll[n];

    s[n-1] = a[n-1];
    for (int i = n-1; i > 1; i--) {
        s[i-1] = s[i] + a[i-1];
        s[i-1] %= mod;
    }

    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += a[i]*s[i+1];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}