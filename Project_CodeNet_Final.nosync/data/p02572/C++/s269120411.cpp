#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        sum -= A[i];
        ans += A[i] * (sum % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}