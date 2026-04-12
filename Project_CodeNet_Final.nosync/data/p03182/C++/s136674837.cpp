#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

struct node {
    int s, e, m; ll v, lz;
    node *l, *r;
    node(int _s, int _e): s(_s), e(_e), m((_s+_e)/2), v(0), lz(0) {
        if (s != e) {
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    
    void prop() {
        if (lz == 0) return;
        if (s != e) {
            l->lz += lz;
            r->lz += lz;
        }
        v += lz;
        lz = 0;
    }

    void update(int x, int y, ll z) {
        assert(x <= y);
        //cout << "UPDATE " << s << " " << e << " :: " << x << " " << y << endl;
        //if (x == 3 and y == 3) cout << "AHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
        if (s == x && e == y) { lz += z; return; }
        else if (y <= m) l->update(x, y, z);
        else if (x >  m) r->update(x, y, z);
        else l->update(x, m, z), r->update(m+1, y, z);

        l->prop();
        r->prop();
        v = min(l->v, r->v);
    }

    ll qmin(int x, int y) {
        prop();
        if (s == x && e == y) return v;
        if (y <= m) return l->qmin(x, y);
        if (x >  m) return r->qmin(x, y);
        return min(l->qmin(x, m), r->qmin(m+1, y));
    }

    void dbg(string pre="|") {
        cout << pre << "> " << s << " " << e << " :: " << v << " " << lz << endl;
        if (s != e) l->dbg(pre+"--"), r->dbg(pre+"--");
    }
} *seg;

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ii> event[n+1];
    ll total = 0;
    FOR(i,0,m-1) {
        int l, r, a; cin >> l >> r >> a;
        event[l].emplace_back(r, a);
        total += a;
    }

    seg = new node(1, n+2);
    ll dp[n+2]; dp[n+1] = 0;

    RFOR(x,n,1) {
        for (auto e : event[x]) {
            seg->update(e.fi+2, n+2, e.sc);
            //cout << "\t\tEVENT " << e.fi+2 << " to " << n+2 << " by " << e.sc << endl;
        }

        //cout << "TEST " << seg->qmin(x+1, n+1) << endl;
        //cout << "\t\tTEST ";
        //FOR(i,1,n+2) cout << seg->qmin(i,i) << ' ';
        //cout << endl;
        //seg->dbg();

        dp[x] = min(dp[x+1], seg->qmin(x+1, n+2));
        seg->update(x, x, dp[x]);
        //cout << "\t\tUPDATE " << x << " by " << dp[x] << endl;
        //cout << x << " :: " << dp[x] << endl;
    }

    cout << total - dp[1] << '\n';
}

