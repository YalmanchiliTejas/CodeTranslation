#include <bits/stdc++.h>
using namespace std;

long long N, K;
string S;

long long pow(long long N, long long K) {
    long long res = 1;
    for (int i = 0; i < K; i++)
    {
        res *= N;
    }
    return res;
}

long long com(long long N, long long R) {
    if(N < R || R < 0) return 0;
    if(R == 1) return N;
    else if(R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

long long solve(int i, int k, int smaller) {
    if(i == N) {
        if(k == 0) return 1;
        else return 0;
    }
    if(k == 0) return 1;

    if(smaller) return com(N-i, k) * pow(9, k);
    else {
        if(S[i] == '0') return solve(i+1, k, false);
        else {
            long long zero = solve(i+1, k, true);
            long long aida = solve(i+1, k-1, true) * (S[i] - '1');
            long long icchi = solve(i+1, k-1, false);
            return zero + aida + icchi;
        }
    }
}

int main() {
    cin >> S >> K;
    N = S.size();
    cout << solve(0, K, false) << endl;
    return 0;
}