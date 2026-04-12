#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll a;
    deque<ll> q;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        if ( i & 1 ) q.push_front(a);
        else q.push_back(a);
    }
    for ( int i = 0; i < N; i++ ) {
        int j = i;
        if ( N & 1 ) j = N - 1 - i;
        cout << q[j] << " ";
    }
    cout << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}