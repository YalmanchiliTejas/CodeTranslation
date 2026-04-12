#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    ll N, X, M; cin >> N >> X >> M;
    vector<ll> ms = {X};
    set<ll> mset = {X};
    ll tmp = X*X % M;
    while (!mset.count(tmp) && ms.size() < N) {
        ms.push_back(tmp);
        mset.insert(tmp);
        tmp = tmp*tmp % M;
    }
    if (ms.size() == N) {
        ll ans = 0;
        rep(i, (int)N) ans+=ms[i];
        cout << ans << endl;
        return 0;
    }
    int tmpPos = 0;
    ll ans = 0;
    while(ms[tmpPos] != tmp) {
        ans += ms[tmpPos];
        tmpPos++;
    }
    N-=tmpPos;
    for (int i = 0; i < ms.size()-tmpPos; i++) {
        ans += N/(ms.size()-tmpPos) * ms[tmpPos+i];
        if (i < N%(ms.size()-tmpPos)) ans += ms[tmpPos+i];
    }
    cout << ans << endl;
}
