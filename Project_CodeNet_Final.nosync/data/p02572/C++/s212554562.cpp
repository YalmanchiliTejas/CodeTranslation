#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int N, a[maxn];
long long sum[maxn];
int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i], sum[i+1] = sum[i] + a[i];
    int ans = 0;
    for(int i = 0; i < N-1; ++i) {
        ans = (ans + a[i] * ((sum[N] - sum[i+1]) % mod)) % mod;// [i+1, N-1]
    }
    cout << ans << endl;
    return 0;
}
