#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    sort(begin(A), end(A));
    
    if(N % 2 == 0) {
        long long res = 0;
        int n = (N - 2) / 2;
        for(int i=0; i<n; ++i) {
            res += 2LL * A[N - 1 - i];
            res -= 2LL * A[i];
        }
        res += A[n + 1] - A[n];
        cout << res << endl;
    } else {
        long long res1 = 0, res2 = 0;
        int n1 = (N - 3) / 2;
        int n2 = (N - 1) / 2;
        for(int i=0; i<n1; ++i) {
            res1 += 2LL * A[N - 1 - i];
            res2 -= 2LL * A[i];
        }
        for(int i=0; i<n2; ++i) {
            res1 -= 2LL * A[i];
            res2 += 2LL * A[N - 1 - i];
        }
        res1 += A[n2] + A[n2 + 1];
        res2 -= A[n1] + A[n1 + 1];
        cout << max(res1, res2) << endl; 
    }
}
