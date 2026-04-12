#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll a[200005] = {}, z = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], z += a[i], y += a[i] * a[i] % mod;
    z %= mod; y %= mod;
    cout << (z * z - y) % mod * 500000004 % mod;
}
