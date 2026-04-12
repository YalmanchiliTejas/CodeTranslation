#include <iostream>
#include <vector>

#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll J = 0;
    ll ans = 0;
    for (int i = N - 2; i >= 0; --i) {
        J += A[i + 1];
        J = J % MOD;
        ans += A[i] * J;
        ans = ans % MOD;
    }

    cout << ans <<endl;

    return 0;
}