#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

int n;
pll p[200010];
lint m, M;

lint solve1(){
    set<pll> s;
    rep(i, n){
        if(p[i].fi > p[i].se) swap(p[i].fi, p[i].se);
        s.insert(p[i]);
    }
    lint ret = 1e18;
    rep(i, n){
        ret = min(ret, ((*s.rbegin()).fi - (*s.begin()).fi) * (M-m));
        pll tp = *s.begin();
        if(tp.fi > tp.se) break;
        s.erase(tp);
        s.insert(make_pair(tp.se, tp.fi));
    }
    return ret;
}

lint solve2(){
    lint rM = 0;
    lint bm = 1e18;
    rep(i, n){
      	if(p[i].fi > p[i].se) swap(p[i].fi, p[i].se);
        rM = max(rM, p[i].fi);
        bm = min(bm, p[i].se);
    }
    return (M-bm) * (rM-m);
}

int main(){
    scanf("%d", &n);
    m = 1e18;
    M = 0;
    rep(i, n){
        lint a, b;
        scanf("%lld%lld", &a, &b);
        p[i] = make_pair(a, b);
        m = min({m, a, b});
        M = max({M, a, b});
    }
    printf("%lld\n", min(solve1(), solve2()));
}