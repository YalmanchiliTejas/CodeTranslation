#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
typedef long long lint;
template <class T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
/* templates */ /* templates */ /* templates */ /* templates */ /* templates */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int H[N];
    rep(i, N) { cin >> H[i]; }
    int tmpmax = 0, ans = 0;
    rep(i, N) {
        if(H[i] >= tmpmax) {
            ans++;
        }
        chmax(tmpmax, H[i]);
    }
    cout << ans << endl;
}