#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    int64_t A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int64_t sum = 0;
    int64_t X = 0;
    for (int i = 0; i < N; i++) {
        X = X + A[i];
        X = X % 1000000007;
    }

    for (int i = 0; i < N - 1; i++) {
        int64_t Y;
        if (X - A[i] % 1000000007 < 0) {
            X = X + 1000000007;
        }
        X = X - A[i] % 1000000007;
        Y = A[i] * X;
        Y = Y % 1000000007;
        sum = sum + Y;
        sum = sum % 1000000007;
    }
    cout << sum << endl;

}