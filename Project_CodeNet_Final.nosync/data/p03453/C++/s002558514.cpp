#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define INF 0X3F3F3F3F
#define N 100005
#define M 200005
#define LL long long
#define ULL unsigned long long
#define FF(i, a, b) for(int i = a; i <= b; ++i)
#define RR(i, a, b) for(int i = a; i >= b; --i)
#define FJ(i, a, b) for(int i = a; i < b; ++i)
#define SC(x) scanf("%d", &x)
#define SCC(x, y) scanf("%d%d", &x, &y)
#define SCCC(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SS(x) scanf("%s", x)
#define PR(x) printf("%d\n", x)
#define CL(a, x) memset(a, x, sizeof(a))
#define _P fd[rt]
#define _L fd[rt << 1]
#define _R fd[rt << 1 | 1]
#define MID int mid = ((l + r) >> 1)
#define lson rt<<1 ,l, mid
#define rson rt<<1 | 1, mid + 1, r
#define VI vector<int>
#define db double
#define PII pair<int, int>
#define PLL pair<unsigned long long, unsigned long long>
#define MP make_pair
#define PB push_back
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
using namespace std;
inline void II(int &n){char ch = getchar(); n = 0; bool t = 0;
for(; ch < '0'; ch = getchar()) if(ch == '-') t = 1;
for(; ch >= '0'; n = n * 10 + ch - '0', ch = getchar()); if(t) n =- n;}
inline void OO(int a){if(a < 0) {putchar('-'); a = -a;}
if(a >= 10) OO(a / 10); putchar(a % 10 + '0');}
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
int sgn(double x){return (x > EPS) - (x < -EPS);}
int hd[N], EN;
struct node{
    int u, v, w, nx;
}E[400100 * 2];
vector<int> G[N];
vector<int> RG[N];
void add_edge(int u, int v, int w){
    E[EN].w = w; E[EN].v = v; E[EN].nx = hd[u]; hd[u] = EN++;
    E[EN].w = w; E[EN].v = u; E[EN].nx = hd[v]; hd[v] = EN++;
}
int n, m, u, v, w, in[N], S, T;
long long f[N], g[N];
int fc[N], gc[N];
int ee[M][3];
bool ok[M], vis[N];
int main(){
   // IN;
    SCC(n, m);
    SCC(S, T);
    EN = 0;
    memset(hd, -1, sizeof hd);
    FF(i, 1, m){
        SCCC(u, v, w);
        ee[i][0] = u; ee[i][1] = v; ee[i][2] = w;
        ++in[v];
        add_edge(u, v, w);
    }
    memset(f, 0x3f, sizeof f);
    f[S] = 0;
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int k = hd[u], v; v = E[k].v, ~k; k = E[k].nx){
            if(f[u] + E[k].w < f[v]){
                f[v] = f[u] + E[k].w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    memset(g, 0x3f, sizeof g);
    g[T] = 0;
    q.push(T);
    memset(vis, 0, sizeof vis);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int k = hd[u], v; v = E[k].v, ~k; k = E[k].nx){
            if(g[u] + E[k].w < g[v]){
                g[v] = g[u] + E[k].w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    long long dis = f[T];
   // cout << dis << endl;
    memset(in, 0, sizeof in);
    FF(i, 1, m){
        if(f[ee[i][0]] + g[ee[i][1]] + ee[i][2] == dis){
           // printf("%d %d\n", ee[i][0], ee[i][1]);
            ok[i] = 1;
            G[ee[i][0]].PB(ee[i][1]);
            ++in[ee[i][1]];
            RG[ee[i][1]].PB(ee[i][0]);
        }
        if(f[ee[i][1]] + g[ee[i][0]] + ee[i][2] == dis){

           // printf("%d %d\n", ee[i][1], ee[i][0]);
            swap(ee[i][0], ee[i][1]);

            ++in[ee[i][1]];
            ok[i] = 1;
            G[ee[i][0]].PB(ee[i][1]);
            RG[ee[i][1]].PB(ee[i][0]);
        }
    }
    q.push(S);
    fc[S] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &v : G[u]){
            (fc[v] += fc[u]) %= MOD;
            --in[v];
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    memset(in, 0, sizeof in);
    FF(i, 1, m) if(ok[i]){
        ++in[ee[i][0]];
    }
    q.push(T);
    gc[T] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &v : RG[u]){
            (gc[v] += gc[u]) %= MOD;
            --in[v];
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    long long ans = 1LL * fc[T] * fc[T] % MOD, l, r;
    FF(i, 1, m) if(ok[i]){
        u = ee[i][0];
        v = ee[i][1];
        l = f[u];
        r = g[v];
        if(min(l, r) + ee[i][2] > max(l, r))
            (ans += MOD - ((1LL * fc[u] * gc[v] % MOD)

* (1LL * fc[u] * gc[v] % MOD)%MOD)
)

 %= MOD;
    }
    FF(i, 1, n) if(f[i] == g[i]){
        (ans += MOD - ((1LL * fc[i] * gc[i] % MOD)

*(1LL * fc[i] * gc[i] % MOD)%MOD)

) %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
