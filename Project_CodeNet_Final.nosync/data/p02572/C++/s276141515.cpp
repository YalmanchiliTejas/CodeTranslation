#include<bits/stdc++.h>
using namespace std;
using lint = long int;
#define MOD 1000000007

int N;
lint A[200010];
lint sumA = 0;  //Aの和
lint res = 0;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) sumA += A[i];
    sumA %= MOD;  //剰余

    for(int i = 0; i < N-1; i++){  //A[i]との積...A[i+1]~A[N-1]
        sumA -= A[i];
        if(sumA <= 0) sumA += MOD;  //sumAが0以下なら+MODでsumA<=MOD
        res += A[i] * sumA;  //long int範囲を超越しない演算
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}