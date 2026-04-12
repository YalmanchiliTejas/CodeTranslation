#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll x, y, z; cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;
}
