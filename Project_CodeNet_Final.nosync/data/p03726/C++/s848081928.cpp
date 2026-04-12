#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"First\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

int deg[maxn];
int col[maxn];
int nf[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > g(n);
    REP(i,n-1){
        int a, b; cin>>a>>b; g[a-1].pb(b-1); g[b-1].pb(a-1);
        deg[a-1]++; deg[b-1]++;
    }
    queue<int> cd;
    REP(i,n){
        for (int v : g[i]) {
            if (deg[v]==1) nf[i]++;
        }
        if (nf[i]==1) cd.push(i);
        if (nf[i]>1) GG();
    }
    while (!cd.empty()){
        int t = cd.front(); cd.pop();
        col[t] = 1; 
        // cout<<"Painted "<<t+1<<endl;
        for (int v : g[t]) {
            deg[v]--;
            if (deg[v]==0) col[v] = 2;
            else if (deg[v]==1){
                for (int u : g[v]){
                    if (col[u]) continue;
                    nf[u]++; if (nf[u]>1) GG();
                    cd.push(u);
                }
            }
        }
    }
    REP(i,n){
        if (col[i] == 1){ int mo = 1;
            for (int v : g[i]){
                if (col[v]==2) {
                    mo = 0; break;
                }
            } if (mo) GG();
        }
    }
    cout<<"Second"<<endl;
} 