#include <bits/stdc++.h>
using namespace std;
long long A[51];
long long P[51];

void init() {
    A[0] = 1; P[0] = 1;
    for(int i=0; i<50; ++i) {
        A[i+1] = 2 * A[i] + 3;
        P[i+1] = 2 * P[i] + 1;
    }
}

long long solve(int N, long long X) {
    if(N == 0) {
        if(X) return 1;
        else return 0;
    }
    if(X == 1) return 0;
    else if(X <= A[N-1] + 1) return solve(N - 1, X - 1);
    else if(X == A[N-1] + 2) return P[N-1] + 1;
    else if(X <= 2 * A[N-1] + 2) return P[N-1] + 1 + solve(N-1, X - A[N-1] - 2);
    else return 2 * P[N-1] + 1;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    init();
    cout << solve(N,X) << endl;
}