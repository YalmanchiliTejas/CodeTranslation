#include <bits/stdc++.h>
#define int long long
#define P(x) cout << x << endl
#define D(x) P(#x << ": " << x)
#define F(i,n) for (int i=0; i<(int)(n); i++)
#define DEC(i,n) for (int i=(int)(n); --i>=0;)
#define S(s) (int)((s).size())
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,(v))
#define MA(a,v) a = max(a,(v))
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
const int N=1e5;

struct res {bool take,no;};
V<int> adj[N];

res dp(int u, int par) {
    V<res> ch;
    for (int v : adj[u]) if (v != par)
        ch.pb(dp(v,u));
    int numTake=0;
    for (res r : ch)
        numTake += r.take;
    res me;
    me.no = (numTake == S(ch));
    me.take = false;
    for (res r : ch) {
        if (r.no && (numTake - r.take == S(ch)-1))
            me.take = true;
    }
    return me;
}

signed main() {
    int n; cin>>n;
    F(i,n-1) {
        int a,b; cin>>a>>b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    res root = dp(0,-1);
    if (root.take) P("Second");
    else P("First");
}