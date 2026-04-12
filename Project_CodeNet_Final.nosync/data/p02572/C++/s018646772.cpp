#include <iostream>
#include <vector>
using namespace std;
const long mod = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        b[i] = (a[i] + b[i + 1]) % mod;
    }
    int r = 0;
    for (int i = 0; i < n - 1; i++) {
        r = r + (a[i] * b[i + 1]) % mod;
        r %= mod;
    }
    cout << r << endl;
}
