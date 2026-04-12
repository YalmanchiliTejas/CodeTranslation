#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int N;
const int MAX_N = 2.0e5 + 100;
ll A[MAX_N];
const int MOD = 1.0e9 + 7;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int A_sum[N+1];
    memset(A_sum, 0, sizeof(A_sum));
    A_sum[N] = 0;
    for (int i = N-1; i >= 0; i--) {
        A_sum[i] = (A_sum[i+1] + A[i]) % MOD;
    }

    ll sum = 0;
    for (int i = 0; i < N-1; i++) {
        sum = (sum + (A[i] * A_sum[i+1]) % MOD ) % MOD;
    }

    cout << sum << endl;

    return 0;
}
