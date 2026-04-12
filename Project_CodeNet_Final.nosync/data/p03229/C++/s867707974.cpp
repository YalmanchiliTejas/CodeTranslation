#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    ll ans = 0;
    if (N % 2 == 0) {
        for (int i = 0; i < N/2 - 1; i++) ans += 2 * A[i];
        ans += A[N/2-1];
        ans -= A[N/2];
        for (int i = N/2 + 1; i < N; i++) ans -= 2 * A[i];        
    } else {
        ll t1 = 0, t2 = 0;
        int m = (N-1)/2;
        
        for (int i = 0; i < m-1; i++) t1 += 2 * A[i];
        t1 += A[m-1] + A[m];
        for (int i = m+1; i < N; i++) t1 -= 2 * A[i];
        
        for (int i = 0; i < m; i++) t2 += 2 * A[i];
        t2 -= A[m] + A[m+1];
        for (int i = m+2; i < N; i++) t2 -= 2 * A[i];

        ans = max(t1, t2);
    }
    cout << ans << endl;
}