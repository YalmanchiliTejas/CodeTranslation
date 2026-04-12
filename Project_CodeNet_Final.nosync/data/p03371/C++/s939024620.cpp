#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll res = 1ll<<60;
    rep(ab, 2*max(x, y) + 1){
        int nx = max(0ll, x-ab/2);
        int ny = max(0ll, y-ab/2);

        res = min(res, nx*a + ny*b + ab*c);
    }

    cout << res << endl;

    return 0;
}