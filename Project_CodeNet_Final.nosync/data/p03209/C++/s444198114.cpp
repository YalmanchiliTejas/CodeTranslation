#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    ll N, X;
    cin >> N >> X;
    ll ans = 0;
    vector<ll> level(51, 0), ps(51, 0);
    level[0] = 1;
    ps[0] = 1;
    for (int i=1; i<=N; ++i) {
        level[i] = level[i-1]*2LL+3LL;
        ps[i] = ps[i-1]*2LL+1LL;
    }
    if (X == level[N]) {
        cout << ps[N] << endl;
        return 0;
    }
    else if (X <= N) {
        cout << 0 << endl;
        return 0;
    }

    for (int cur=N; cur>=0; --cur) {
        if (X+1 == level[cur]) {
            ans += ps[cur];
            break;
        }
        else if (X > level[cur]/2) {
            ans += ps[cur-1]+1;
            X -= level[cur-1]+2;
            //if (X > level[cur-1]) X--;
        }
        else if (X == level[cur]/2) {
            ans += ps[cur-1];
            X -= level[cur-1]+1;
            //if (X > level[cur-1]) 
        }
        else {
            X--;
        }
        if (X == 0) break;
    }
    cout << ans << endl;
}
