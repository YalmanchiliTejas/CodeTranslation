#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int mod = 1'000'000'007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    int x = 0;
    for(int i = 0; i < n; ++i) {
        ans = (ans+(ll)a[i]*x) % mod;
        x = (x+a[i]) % mod;
        }
    cout << ans << endl;
    return 0;
}