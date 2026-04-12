#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int inf =1 << 30;
const ll mod=1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b,const ll &mod) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b,const ll &mod) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b,const ll &mod) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b,const ll &mod) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1,6);
uniform_real_distribution<double> score(0.0,10.0);

const int N = 4;
bool canp[N][N][N+1][N+1];

int main(void){
    int n; cin >> n;
    vi hs(n), ws(n);
    rep(i, n) cin >> hs[i] >> ws[i];

    vector<string> field(N);
    for(auto & e : field) cin >> e;

    rep(i, n){
        int h = hs[i], w = ws[i];

        rep(y, N){
            rep(x, N){
                int lh = h;
                if(y == 0 or y == 3) lh = 1;

                int lw = w;
                if(x == 0 or x == 3) lw = 1;

                rep(hh, lh, h + 1){
                    rep(ww, lw, w + 1){
                        canp[y][x][min(hh, N - y)][min(ww, N - x)] = true;
                    }
                }
            }
        }
    }

    assert(canp[0][0][1][1]);
    assert(canp[3][3][1][1]);
    assert(canp[0][3][1][1]);
    assert(canp[3][0][1][1]);

    queue<int> q;
    q.push(0);
    vi min_dist(1 << (N * N), inf);
    min_dist[0] = 0;

    string colors = {'R', 'G', 'B'};
    while(q.size()){
        int state = q.front(); q.pop();

        rep(y, N){
            rep(x, N){
                rep(h, 1, N - y + 1){
                    rep(w, 1, N - x + 1){
                        if(not canp[y][x][h][w]) continue;

                        for(auto & c : colors){
                            int nstate = state;
                            rep(yy, y, y + h){
                                rep(xx, x, x + w){
                                    if(field[yy][xx] == c){
                                        nstate |= (1 << (yy * 4 + xx));
                                    }
                                    else {
                                        nstate &= ~(1 << (yy * 4 + xx));
                                    }
                                }
                            }
                            if(chmin(min_dist[nstate], min_dist[state] + 1)){
                                if(nstate == (1 << (N * N)) - 1){
                                    cout << min_dist[nstate] << endl;
                                    return 0;
                                }
                                q.push(nstate);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}