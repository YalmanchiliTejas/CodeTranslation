#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N; cin >> N;
    long long A[N];
    rep(i,N) cin >> A[i];
    long long sum = 0;
    rep(i,N) sum += A[i];
    for (long long i = sum-N*(N-1); ; i++) {
        sum = 0;
        rep(j,N) sum += (A[j]+i+1)/(N+1);
        if (sum <= i) {cout << i << endl; return 0;}
    }
}