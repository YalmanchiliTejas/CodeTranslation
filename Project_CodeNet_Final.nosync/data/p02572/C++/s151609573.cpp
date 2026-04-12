#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    long long MOD = 1e9 + 7;
    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum = (sum + A[i]) % MOD;
    }
    long long ans = 0;
    for(int i = 0; i < N - 1; i++){
        sum = (sum - A[i] + MOD) % MOD;
        ans = (ans + A[i] * sum % MOD) % MOD;
    }
    cout << ans << endl;
}