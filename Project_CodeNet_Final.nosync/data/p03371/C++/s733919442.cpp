#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int res = -1;
    rep(c, 0, 2 * (X > Y ? X : Y) + 1) {
        int m = A * max(X - c/2, 0) + B * max(0,Y - c/2) + C * c;
        if (m < res || res == -1) res = m;
    }
    cout << res << endl;
}