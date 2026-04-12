#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0, squaresum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
        squaresum += (a[i] * a[i]) % mod;
        squaresum %= mod;
    }
    long long ans = sum * sum - squaresum;
    ans %= mod;
    if(ans & 1) ans = (ans + mod) / 2;
    else ans = ans / 2;
    cout << ans << endl;
}