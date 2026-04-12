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
    int n;
    ll m, a[55] = {1}, b[55] = {1}, z = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] * 2 + 1, b[i] = b[i - 1] * 2 + 3;
    for (int i = n; i >= 0; i--) {
        if (!i) {
            if (m > 0) z++;
        } else if (m >= b[i - 1] + 1) {
            z += a[i - 1];
            if (m >= b[i - 1] + 2) z++;
            m -= b[i - 1] + 2;
        } else {
            m--;
        }
    }
    cout << z;
}
