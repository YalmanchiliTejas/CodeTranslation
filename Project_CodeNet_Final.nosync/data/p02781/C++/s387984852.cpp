#include <bits/stdc++.h>
using namespace std;

long long is(long long N, long long R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

string S;
int N, K;

long long solve(int i, int k, int how) {
    if (i == N) {
        if (k == 0) return 1;
        else return 0;
    }
    if (k == 0) return 1;

    if (how) return is(N-i, k) * pow(9, k);
    else {
        if (S[i] == '0') return solve(i+1, k, 0);
        else {
            return  solve(i+1, k, 1)
             + solve(i+1, k-1, 1) * (S[i] - '1')
             + solve(i+1, k-1, 0);
        }
    }
}

int main() {
    cin >> S >> K;
    N = S.size();
    cout << solve(0, K, false) << endl;
}
