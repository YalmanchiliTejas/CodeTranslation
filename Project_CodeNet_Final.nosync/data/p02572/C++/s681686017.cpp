#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int N;
    cin >> N;

    vector<int64_t> A(N), Sum(N-1, 0);
    for(int i = 0; i < N; i++) cin >> A.at(i);

    Sum.at(0) = A.at(N-1) % MOD;
    for(int i = 1; i < N-1; i++) Sum.at(i) = (Sum.at(i-1) + A.at(N-1-i)) % MOD;

    int64_t ans = 0;

    for(int i = 0; i < N-1; i++){
        ans += Sum.at(N-2-i) * A.at(i) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}