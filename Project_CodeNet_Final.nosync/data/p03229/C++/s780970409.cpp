#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 1.0e5 + 100;
ll A[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N, greater<>());

    ll ans = 0;
    if (N % 2 == 0) {
        for (int i = 0; i < N; i++) {
            if (i < N/2 - 1) ans += 2*A[i];
            else if (i == N/2 - 1) ans += A[i];
            else if (i == N/2) ans -= A[i];
            else ans -= 2*A[i];
        }
    }
    else {
        ll a1 = 0;
        for (int i = 0; i < N; i++) {
            if (i < N/2 - 1) a1 += 2*A[i];
            else if (i == N/2 - 1) a1 += A[i];
            else if (i == N/2) a1 += A[i];
            else a1 -= 2*A[i];
        }
        ll a2 = 0;
        for (int i = 0; i < N; i++) {
            if (i < N/2) a2 += 2*A[i];
            else if (i == N/2) a2 -= A[i];
            else if (i == N/2 + 1) a2 -= A[i];
            else a2 -= 2*A[i];
        }
        ans = max(a1, a2);
    }

    cout << ans << endl;
    
    return 0;
}
