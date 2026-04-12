#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<ull> A(N);
    ull A_sum = 0;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        A_sum += A[i];
    }
    ull sum = 0;
    for (int i=0; i<N-1; i++) {
        A_sum = A_sum - A[i];
        ull A_sum_mod = A_sum % 1000000007;
        sum += A[i] * A_sum_mod;
        sum = sum % 1000000007;
    }
    cout << sum << endl;
}