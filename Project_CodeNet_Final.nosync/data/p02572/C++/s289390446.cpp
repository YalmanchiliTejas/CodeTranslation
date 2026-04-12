#include <bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD{1000000007};
    unsigned long N;
    cin >> N;
    unsigned long S{0}, T{0};
    for(unsigned long i{0}, A; i < N; ++i){
        cin >> A;
        (S += A) %= MOD;
        (T += A * A) %= MOD;
    }
    cout << (S * S % MOD + MOD - T) * (MOD + 1) / 2 % MOD << endl;
    return 0;
}