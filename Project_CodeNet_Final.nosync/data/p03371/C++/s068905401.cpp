#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int A, B, C, X, Y;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> A >> B >> C >> X >> Y;
    int ans = 1000000000;
    for (int i=0; i<=200100; i+=2) ans = min(ans, max(0ll, X-i/2)*A+max(0ll, Y-i/2)*B+i*C);
    cout << ans << endl;
}