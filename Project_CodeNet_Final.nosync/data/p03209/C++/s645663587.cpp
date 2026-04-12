#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;

vector<ll> m(51), n(51);
 
ll sub(int N, ll X) {
    if (N == 0) { return X; }
    ll w = m[N-1];
    if (X <= 1) return 0;
    X -= 1;
    if (X <= w) return sub(N-1, X);
    X -= w;
    if (X <= 1) return n[N-1] + X;
    X -= 1;
    if (X <= w) return n[N-1] + 1 + sub(N-1, X);
    X -= w;
    return n[N];
}
 
ll solve(int N, ll X) {
    return sub(N, X);
}
 
int main() {
    m[0] = n[0] = 1;
    for (int i=1; i<=50; ++i) {
        m[i] = m[i-1]*2 + 3;
        n[i] = n[i-1]*2 + 1;
    }
 
 
    int N; ll X;
    cin >> N >> X;
    cout << solve(N,X) << endl;
    return 0;
}