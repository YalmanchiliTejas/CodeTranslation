#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (X>Y) {
        cout << min(A*X+B*Y, min(C*Y*2+A*(X-Y), C*X*2)) << endl;
    } else {
        cout << min(A*X+B*Y, min(C*X*2+B*(Y-X), C*Y*2)) << endl;
    }
}