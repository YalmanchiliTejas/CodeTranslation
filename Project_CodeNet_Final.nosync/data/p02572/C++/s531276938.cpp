#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long inverse2 = 500000004;
int main(){
    int n; cin >> n;
    vector<long long> A(n); long long sum = 0, square = 0;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i]; sum %= MOD;
        square += A[i] * A[i]; square %= MOD;
    }
    sum *= sum; sum %= MOD;
    sum = (sum - square + MOD) % MOD; sum *= inverse2; sum %= MOD;
    cout << sum << '\n';
    return 0;
}