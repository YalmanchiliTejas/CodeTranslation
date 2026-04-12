#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < N / 2; i++) {
        sum1 += A[i];
        sum2 += A[N - 1 - i];
    }

    if (N % 2 == 0) {
        cout << sum2 - sum1 + (sum2 - A[N / 2]) - (sum1 - A[N / 2 - 1]) << endl;
    } else {
        cout << sum2 - sum1 + max(sum2 - (sum1 - A[N / 2 - 1] + A[N / 2]), (sum2 - A[N / 2 + 1] + A[N / 2]) - sum1) << endl;
    }
    return 0;
}