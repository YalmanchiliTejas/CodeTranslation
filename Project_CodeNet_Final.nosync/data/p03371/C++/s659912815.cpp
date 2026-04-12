#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int l = max(X,Y);
    ll ans = 10000000050;
    for(int i=0;i<=l;i++) {
        ll n = 2*C*i + max(0, X-i)*A + max(0, Y-i)*B;
        ans = min(ans, n);
    }
    cout << ans << endl;
}