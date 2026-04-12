#include <iostream>
using namespace std;

const int MOD = 1000000007;
int main(void){
    int N, Abuf;
    long long sumA = 0LL;
    long long sumsqA = 0LL;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> Abuf;
        sumA += Abuf;
        sumA %= MOD;
        sumsqA += (long long)Abuf * Abuf;
        sumsqA %= MOD;
    }
    cout << (sumA*sumA%MOD + MOD-sumsqA)%MOD * 500000004 % MOD << endl;
    return 0;
}