#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
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
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

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

vector<int> G[MAX_N];
bool ok;

int dfs(int u, int p)
{
    if(u == 0){
        if(len(G[u]) == 1){
            int res = dfs(G[u][0], u);
            if(ok) return 0;
            ok = (res^1);
            return 0;
        }else{
            int cnt = 0;
            each(v, G[u]){
                cnt += dfs(v, u);
                if(ok) return 0;
                if(cnt > 1){
                    ok = true;
                    return 0;
                }
            }
            ok = (cnt^1);
            return 0;
        }
    }else{
        if(len(G[u]) == 1){
            return 1;
        }else if(len(G[u]) == 2){
            each(v, G[u]){
                if(v != p){
                    int res = dfs(v, u);
                    if(ok) return 0;
                    return res^1;
                }
            }
        }else{
            int cnt = 0;
            each(v, G[u]){
                if(v != p){
                    cnt += dfs(v, u);
                    if(ok) return 0;
                    if(cnt > 1){
                        ok = true;
                        return 0;
                    }
                }
            }
            return cnt^1;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b), G[b].pb(a);
    }
    dfs(0, -1);
    if(ok){
        cout << "First\n";
    }else{
        cout << "Second\n";
    }
    return 0;
}
