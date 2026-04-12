#include"bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto B = A;
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        if (A[i] < B[N / 2]) {
            cout << B[N / 2] << endl;
        } else {
            cout << B[N / 2 - 1] << endl;
        }
    }
}