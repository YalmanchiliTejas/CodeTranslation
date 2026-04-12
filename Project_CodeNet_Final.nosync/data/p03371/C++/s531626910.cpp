#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define out(a) cout << a << endl
#define outa(a, n) rep(_, n) cout << a[_] << " "; cout << endl
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = inf;
    rep(c, 200001) {
        int a = max(0, X - c / 2);
        int b = max(0, Y - c / 2);
        chmin(ans, A * a + B * b + C * c);
    }
    out(ans);
}
