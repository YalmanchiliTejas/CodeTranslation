
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

#define x st
#define y nd

struct FAU {
    VI p, r;

    FAU(int n): p(n,-1), r(n,0) {}

    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    void join(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return ;

        if (r[x] > r[y]) p[y] = x;
        else p[x] = y;

        if (r[x] == r[y]) ++r[y];
    }
};

/*************************************************************************/

int dist(pii a, pii b) {
    return min(abs(a.x - b.x), abs(a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    VP pts(n);
    FOR(i,0,n-1) {
        cin >> pts[i].x >> pts[i].y;
    }
    
    VP byX(n), byY(n);
    FOR(i,0,n-1) {
        byX[i] = {pts[i].x, i};
        byY[i] = {pts[i].y, i};
    }
    
    sort(byX.begin(), byX.end());
    sort(byY.begin(), byY.end());
    
    struct edge { int u, v, len; };
    
    vector <edge> edges;
    
    FOR(i,0,n-2) {
        edges.pb({byX[i].nd, byX[i+1].nd, -1});
        edges.pb({byY[i].nd, byY[i+1].nd, -1});
    }
    
    for (auto &e : edges) {
        e.len = dist(pts[e.u], pts[e.v]);
    }
    
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.len < b.len;
    });
    
    FAU fau(n);
    ll ans = 0;
    
    for (auto &e : edges) {
        if (fau.find(e.u) != fau.find(e.v)) {
            fau.join(e.u, e.v);
            ans += e.len;
        }
    }
    
    cout << ans;

    return 0;
}

/*************************************************************************/
