#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli MOD = 1000000007;

int main() {
    int N; cin >> N;
    vector<lli> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    vector<lli> cumsum(N, 0); 
    cumsum[N-1] = A[N-1];
    for (int i=N-2; i>0; i--) {
        cumsum[i] = cumsum[i+1] + A[i];
        cumsum[i] %= MOD;
    }
    lli ans = 0;
    for (int i=0; i<N-1; i++) {
        ans += A[i] * cumsum[i+1];
        ans %= MOD;
    }
    cout << ans << endl;
}