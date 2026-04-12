#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (2 * C < A + B) {
        int res = min(X, Y);
        ans += res * 2 * C;
        X -= res;
        Y -= res;
    } else {
        ans += A * X;
        ans += B * Y;
        X = 0;
        Y = 0;
    }

    if (X) {
        ans += min(A, 2 * C) * X;
    }
    if (Y) {
        ans += min(B, 2 * C) * Y;
    }

    cout << ans << endl;
}