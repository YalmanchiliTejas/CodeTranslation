#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<ll> f(n + 1), g(n + 1);
    f[1] = 0, g[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            f[i] = f[i - 2] + a[i - 2];
            g[i] = max(f[i - 2], g[i - 2]) + a[i - 1];
        } else {
            f[i] = max(f[i - 1], g[i - 1]);
            g[i] = max(f[i - 2], g[i - 2]) + a[i - 1];
        }
    }
    cout << max(f[n], g[n]);
}