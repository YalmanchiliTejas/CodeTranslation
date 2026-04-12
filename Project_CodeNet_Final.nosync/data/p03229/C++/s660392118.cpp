#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end(), greater<long long>());

    if (N % 2 == 0) {
        long long res = 0;
        for (int i = 0; i < N/2 - 1; ++i) res += A[i] * 2;
        res += A[N/2 - 1];
        res -= A[N/2];
        for (int i = N/2 + 1; i < N; ++i) res -= A[i] * 2;
        cout << res << endl;
    }
    else {
        long long res1 = 0;
        for (int i = 0; i < N/2 - 1; ++i) res1 += A[i] * 2;
        res1 += A[N/2 - 1] + A[N/2];
        for (int i = N/2 + 1; i < N; ++i) res1 -= A[i] * 2;
        
        long long res2 = 0;
        for (int i = 0; i < N/2; ++i) res2 += A[i] * 2;
        res2 -= A[N/2] + A[N/2 + 1];
        for (int i = N/2 + 2; i < N; ++i) res2 -= A[i] * 2;
        cout << max(res1, res2) << endl;
    }
}