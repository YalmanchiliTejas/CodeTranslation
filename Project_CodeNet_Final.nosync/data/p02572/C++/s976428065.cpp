#include <iostream>
using namespace std;

long long n, a, tot, ans, mod = 1e9+7;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        ans += tot*a;
        ans %= mod;
        tot += a;
        tot %= mod;
    }
    cout << ans << "\n";
}
