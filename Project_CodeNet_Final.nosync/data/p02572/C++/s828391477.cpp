#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    long ans = 0;

    for (int i = 0; i < n; i++) {
        sum -= A[i];
        if (sum < 0) {
            sum += mod;
        }
        ans += A[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}