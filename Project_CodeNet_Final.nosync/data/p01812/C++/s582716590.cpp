#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int g[101][101];

vector<int> G[(1 << 16)];
int dist[(1 << 16)];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,K;
    cin >> n >> m >> K;
    vi d(m),unzip(n,-1);
    rep(i,m){
        cin >> d[i];
        --d[i];
        unzip[d[i]] = i;
    }
    rep(i,n){
        rep(j,K){
            cin >> g[i][j];
            --g[i][j];
        }
    }
    rep(i,(1 << m)){
        vi pos;
        rep(j,m){
            if((i >> j) & 1){
                pos.pb(d[j]);
            }
        }
        rep(k,K){
            int to = 0;
            rep(j,len(pos)){
                int nx = unzip[g[pos[j]][k]];
                if(nx >= 0){
                    to |= (1 << nx);
                }
            }
            G[i].pb(to);
        }
    }
    rep(i,(1 << m)){
        dist[i] = INF;
    }
    queue<int> que;
    que.push((1 << m)-1);
    dist[(1 << m)-1] = 0;
    while(!que.empty()){
        int p = que.front();
        que.pop();
        rep(i,len(G[p])){
            if(dist[G[p][i]] > dist[p]+1){
                dist[G[p][i]] = dist[p]+1;
                que.push(G[p][i]);
            }
        }
    }
    cout << dist[0] << "\n";
    return 0;
}