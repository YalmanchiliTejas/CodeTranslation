#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main() {
    int N;
    cin >> N;
    ll ninf = (ll)1e16 * (-1);
    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    vector<ll> oddsum(N+1, 0), evensum(N+1, 0), allsum(N+1, 0);
    for (int i = 1; i <= N; i++) {
        oddsum[i] = oddsum[i-1];
        evensum[i] = evensum[i-1];
        allsum[i] = allsum[i-1];
        allsum[i] += A[i];
        if (i%2 == 1) oddsum[i] += A[i];
        else evensum[i] += A[i];
    }
    
    if (N%2 == 0) {
        ll ans = ninf;
        for (int i = 0; i <= N; i += 2) {
            ans = max(ans, oddsum[i] + evensum[N] - evensum[i]);
        }
        cout << ans << endl;
        return 0;
    }
    
    if (N%2 == 1) {
        ll ans = oddsum[N]-A[1];
        ll mi = 0;
        for (int i = 1; i <= N; i+=2) {
            ll rg = evensum[i] - oddsum[i];
            ans = max(ans, oddsum[N]+rg-mi);
            if (i < N) mi = min(mi, evensum[i+1]-oddsum[i+1]);
        }
        cout << ans << endl;
        return 0;
    }
    
    return 0;
}