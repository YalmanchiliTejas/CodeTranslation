#include <bits/stdc++.h>  

using namespace std;

#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int res = INF;
    rep(i, max(X, Y) + 1) {
        int temp = i * 2 * C;
        int latte = X - i, malta = Y - i;
        if(latte >= 0) temp += latte * A;
        if(malta >= 0) temp += malta * B;
        chmin(res, temp); 
    }
    cout << res << endl;
    return 0;
}