#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, a;
    cin >> N;
    priority_queue<ll> qA;
    vector<ll> A;
    ll km = 0;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        A.push_back(a);
        km += a - N + 1;
    }
    ll ans = 0;
    if ( km > 0 ) {
        for ( int i = 0; i < N; i++ ) {
            ll d = ( A[i] + km ) / ( N + 1 );
            ans += d;
            A[i] = A[i] - d*(N+1);
        }
    }
    for ( int i = 0; i < N; i++ ) {
        qA.push(A[i]);
    }

    for(;;) {
        a = qA.top();
        qA.pop();
        if ( a + ans < N ) break;
        ll d = ( a + ans ) / ( N + 1 );
        if ( d <= 0 ) d = 1;
        ans += d;
        ll aa = a - d*(N+1);
        qA.push(aa);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}