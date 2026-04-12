#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int N;
    cin >> N;
    ll S = 0, ans = 0, m = 1000000007;
    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        ans += S*A;
        S += A;
        S %= m, ans %= m;
    }
    cout << ans << endl;
}