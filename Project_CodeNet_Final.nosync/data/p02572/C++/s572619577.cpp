#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int N;
int modulo = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    vector<ll> a(N);
    ll sum = 0, b = 0;

    rep(i, 0, N) { cin >> a[i]; }
    rep(i, 0, N) {
        b += a[i];
        b %= modulo;
    }
    rep(i, 0, N) {
        b -= a[i];
        if(b < 0) {
            b += modulo;
        }
        sum += a[i] * b;
        sum %= modulo;
    }

    cout << sum << endl;
    return 0;
}
