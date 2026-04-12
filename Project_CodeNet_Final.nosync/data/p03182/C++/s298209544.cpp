#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<pll> lis[200100];
ll ans, arr[200100];
struct lazy_seg {
    ll tree[530000], lazy[530000];
    void init(int s = 0, int e = n+1, int idx = 1) {
        tree[idx] = lazy[idx] = 0;
        if (s==e) return;
        init(s,(s+e)/2,idx*2); init((s+e)/2+1,e,idx*2+1);
    }
    void pd(int idx) {
        tree[idx*2]+=lazy[idx];
        lazy[idx*2]+=lazy[idx];
        tree[idx*2+1]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    void pu(int idx) {
        tree[idx] = max(tree[idx*2],tree[idx*2+1]);
    }
    void upd(int S, int E, ll val, int s = 0, int e = n+1, int idx = 1) {
        if (e<S||E<s) return;
        if (S<=s&&e<=E) {
            tree[idx]+=val;
            lazy[idx]+=val;
            return;
        }
        pd(idx);
        upd(S,E,val,s,(s+e)/2,idx*2);
        upd(S,E,val,(s+e)/2+1,e,idx*2+1);
        pu(idx);
    }
    ll getv(int S, int E, int s = 0, int e = n+1, int idx = 1) {
        if (e<S||E<s) return -LINF;
        if (S<=s&&e<=E) return tree[idx];
        pd(idx);
        return max(getv(S,E,s,(s+e)/2,idx*2),getv(S,E,(s+e)/2+1,e,idx*2+1));
    }
} lst;

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int l, r; ll v;
        scanf("%d%d%lld",&l,&r,&v); ans += v;
        lis[r+1].emplace_back(-v,l+1);
    }
    lst.init();
    for (i=2;i<=n+1;i++) {
        for (pll &tmp : lis[i]) lst.upd(0,tmp.second-2,tmp.first);
        if (i==n+1) {
            printf("%lld\n",ans+lst.getv(0,i-1));
            break;
        }
        lst.upd(i,i,lst.getv(0,i-1));
    }

    return 0;
}
