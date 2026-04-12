//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


//二項係数ライブラリ
const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//前処理COMinit()忘れずに


long long pow(long long x, long long n) {
    if (n == 0) return 1;
    long long res = pow(x * x, n / 2);
    if (n & 1) res = res * x;
    return res; 
}


string S;
int N, K;


long long rec(int i, int k, int smaller) {
    if  (i == N) {
        if (k == 0) return 1;
        else return 0;
    }
    if (k == 0) return 1;

    if (smaller) return COM(N-i, k) * pow(9, k);
    else {
        if (S[i] == '0') return rec(i+1, k, false);
        else {
            long long zero = rec(i+1, k, true);
            long long aida = rec(i+1, k-1, true) * (S[i] - '1');
            long long icchi = rec(i+1, k-1, false);
            return zero + aida + icchi;
        }
    }
}


void solve() {
    cin >> S >> K;
    N = S.size();
    COMinit();
    cout << rec(0, K, false) << endl;
}


int main() {
    solve();
    return 0;
}