#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    if (N % 2 == 0) {
        for (int i = N-1; i >= N/2+1; i--) ans += 2*A[i];
        ans += A[N/2];
        ans -= A[N/2-1];
        for (int i = N/2-2; i >= 0 ; i--) ans -= 2*A[i];
    }
    else if (N % 2 == 1) {
        int t = (N-1)/2;
        for (int i = N-1; i >= t+2; i--) ans += 2*A[i];
        ans += max(2*A[t+1]-A[t]-A[t-1], A[t+1]+A[t]-2*A[t-1]);
        for (int i = t-2; i >= 0 ; i--) ans -= 2*A[i];
    }
    cout << ans << endl;
    return 0;
}