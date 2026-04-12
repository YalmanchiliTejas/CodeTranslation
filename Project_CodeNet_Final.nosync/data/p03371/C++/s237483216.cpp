#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    ll a, b, c;
    ll x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 999999999999999999;
    for (ll i = 0; i < 200000; i++) {
        ans = min(ans, i * 2 * c + max((ll)0, x - i) * a + max((ll)0, y - i) * b);
    }
    cout << ans << endl;
}