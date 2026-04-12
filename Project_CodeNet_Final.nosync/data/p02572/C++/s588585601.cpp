#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll mod = 1000000007;
    
    ll B[N + 1]{};
    for (int i = 0; i < N; i++) {
        B[i + 1] = (B[i] + A[i]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += A[i] * (B[N] - B[i + 1] + mod);
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}