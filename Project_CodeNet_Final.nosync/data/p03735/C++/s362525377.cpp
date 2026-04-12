// ※※※ 解答不能 ※※※
// https://atcoder.jp/contests/arc073/submissions/1243838
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(), x.end()

LL calc1(int n, vector<LL> x, vector<LL> y){
    // pattern 1 [min, ???], [???, max]
    rep(i, n) if(x[i] > y[i]) swap(x[i], y[i]);
    sort(all(x));
    sort(all(y));
    return (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
}

LL calc2(int n, vector<LL> x, vector<LL> y){
    // pattern 2 [min, max], [???, ???]
    using P = array<LL, 2>;
    vector<P> v;
    LL mi = 1e18, ma = -1e18;
    multiset<LL> s;
    rep(i, n){
        if(x[i] > y[i]) swap(x[i], y[i]);
        v.pb(P{x[i], y[i]});
        mi = min(mi, x[i]);
        ma = max(ma, y[i]);
        s.insert(x[i]);
    }
    sort(all(v));
    LL ans = (ma - mi) * (*s.rbegin() - *s.begin());
    rep(i, n){
        s.erase(s.find(v[i][0]));
        s.insert(v[i][1]);
        ans = min(ans, (ma - mi) * (*s.rbegin() - *s.begin()));
    }
    return ans;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<LL> x(N), y(N);
    rep(i, N) scanf("%lld %lld", &x[i], &y[i]);
    printf("%lld\n", min(calc1(N, x, y), calc2(N, x, y)));
    return 0;
}