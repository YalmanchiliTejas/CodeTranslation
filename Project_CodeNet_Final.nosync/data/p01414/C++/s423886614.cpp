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

int dist[(1 << 16)];
int s[4][4];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi h(n), w(n);
    rep(i,n){
        cin >> h[i] >> w[i];
    }
    rep(i,4){
        string hoge;
        cin >> hoge;
        rep(j,4){
            if(hoge[j] == 'R'){
                s[i][j] = 0;
            }else if(hoge[j] == 'G'){
                s[i][j] = 1;
            }else{
                s[i][j] = 2;
            }
        }
    }
    rep(i,(1 << 16)){
        dist[i] = INF;
    }
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int p = que.front();
        que.pop();
        rep(i,3){
            rep(j,n){
                srep(k,-h[j]+1,4){
                    srep(l,-w[j]+1,4){
                        int nx = p;
                        srep(t,max(k,0),min(k+h[j],4)){
                            srep(u,max(l,0),min(l+w[j],4)){
                                if((p >> (4*t+u))&1){
                                    if(s[t][u] != i) nx -= (1 << (4*t+u));
                                }else{
                                    if(s[t][u] == i) nx += (1 << (4*t+u));
                                }
                            }
                        }
                        if(dist[nx] > dist[p] + 1){
                            dist[nx] = dist[p] + 1;
                            que.push(nx);
                        }
                    }
                }
            }
        }
    }
    cout << dist[(1 << 16)-1] << "\n";
    return 0;
}
