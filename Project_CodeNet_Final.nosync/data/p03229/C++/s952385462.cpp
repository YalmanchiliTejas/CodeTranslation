#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if ( N % 2 == 0 )  {
        ll s = 0;
        for ( int i = 0; i < N/2; i++ ) {
            s -= A[i];
        }
        for ( int i = N/2; i < N; i++ ) {
            s += A[i];
        }
        s *= 2;
        s += A[N/2-1] - A[N/2];
        return s;
    } else {
        ll s1 = 0, s2 = 0;
        int mid = (N-1)/2;
        for ( int i = 0; i < mid; i++ ) {
            s1 -= A[i];
            s2 -= A[i];
        }
        for ( int i = mid+1; i < N; i++ ) {
            s1 += A[i];
            s2 += A[i];
        }
        s1 += A[mid];
        s2 -= A[mid];
        s1 *= 2;
        s2 *= 2;
        s1 -= A[mid] + A[mid+1];
        s2 += A[mid] + A[mid-1];
        return  max(s1,s2);
    }
    return 0;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
