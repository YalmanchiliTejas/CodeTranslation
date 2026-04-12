#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long ans = 0;
    long long sum = A[N -1];
    for(int i = N - 2; i >= 0; --i) {
        ans += A[i] * (sum % MOD) % MOD;
        ans %= MOD;
        sum += A[i];
    }
    cout << ans << endl;
    return 0;
}