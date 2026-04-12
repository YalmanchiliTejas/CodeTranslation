#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, x, y, z = mod;
    cin >> a >> b >> c >> x >> y;
    for (int i = 0; i <= 200000; i++, i++) {
        int d = x - i / 2, e = y - i / 2;
        z = min(z, max(0, d) * a + max(0, e) * b + i * c);
    }
    cout << z;
}
