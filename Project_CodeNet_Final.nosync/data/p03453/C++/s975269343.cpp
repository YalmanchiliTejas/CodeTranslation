#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <queue>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<vpll> vvpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vvpll g;

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    int s,t;
    scanf("%d %d", &s, &t);
    s--; t--;
    vpi ed;
    vll di;
    forn(i,0,m) {
        int u,v,l;
        scanf("%d %d %d", &u, &v, &l);
        u--; v--;
        g[u].pb(mp(v, l));
        g[v].pb(mp(u, l));
        ed.pb(mp(u,v));
        di.pb(l);
    }
    
    const ll INF = 1e18;
    vector<ll> d (n, INF);
    vll ws(n, 0);
    vi p (n);
    d[s] = 0;
    priority_queue < pair<ll,int> > q;
    q.push (make_pair (0, s));
    ws[s] = 1;
    while (!q.empty()) {
        int v = q.top().second;
        ll cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first;
            ll len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push (make_pair (-d[to], to));
                ws[to] = ws[v];
            }
            else if(d[v] + len == d[to]) {
                ws[to] = (ws[to] + ws[v]) % mod;
            }
        }
    }
    vll ds = d;
    d = vll(n, INF);
    swap(s, t);
    q.push (make_pair (0, s));
    d[s] = 0;
    vll wt(n,0);
    wt[s] = 1;
    while (!q.empty()) {
        int v = q.top().second;
        ll cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first;
            ll len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push (make_pair (-d[to], to));
                wt[to] = wt[v];
            }
            else if(d[v] + len == d[to]) {
                wt[to] = (wt[to] + wt[v]) % mod;
            }
        }
    }
    vll dt = d;
    swap(s, t);
    ll ans = 0;
    ll l = ds[t];
    ll tot = 0;
    forn(i,0,n) {
        if(2*ds[i] == l && 2*dt[i] == l) {
            tot += ws[i]*wt[i]%mod;
            ans = (ans + mod - ws[i]*wt[i]%mod*ws[i]%mod*wt[i]%mod)%mod;
        }
    }
    forn (i,0,m) {
        pi e = ed[i];
        ll dw = di[i];
        int u= e.first;
        int v = e.second;
        if(ds[u]+dw+dt[v]==l && 2*ds[u]<l && 2*dt[v] <l) {
            tot += ws[u]*wt[v]%mod;
            ans = (ans + mod - ws[u]*wt[v]%mod*ws[u]%mod*wt[v]%mod)%mod;
        }
        else if(ds[v]+dw+dt[u]==l && 2*ds[v]<l && 2*dt[u] <l) {
            tot += ws[v]*wt[u]%mod;
            ans = (ans + mod - ws[v]*wt[u]%mod*ws[v]%mod*wt[u]%mod)%mod;
        }
    }
    tot%=mod;
    ans = (ans + tot*tot)%mod;
    cout<<ans<<endl;
//    forn(i,0,n) cout<<ds[i]<<' ';
//    cout<<endl;
//    forn(i,0,n) cout<<dt[i]<<' ';
    
    
    
}
