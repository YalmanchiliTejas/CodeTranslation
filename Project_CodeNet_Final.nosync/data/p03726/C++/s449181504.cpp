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
#define N 200005
#define LL long long
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
#define PB push_back
#define SZ size
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define MP make_pair
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-8;
inline void II(int &n){char ch = getchar(); n = 0; bool t = 0;
for(; ch < '0'; ch = getchar()) if(ch == '-') t = 1;
for(; ch >= '0'; n = n * 10 + ch - '0', ch = getchar()); if(t) n =- n;}
struct EE{int v, nx;}E[N * 4]; int hd[N], EN;
void init_edge(int num){EN = 0; memset(hd, -1, (num + 3) << 2);}
void add_edge(int u, int v){
    E[EN].v = v; E[EN].nx = hd[u]; hd[u] = EN++;
    E[EN].v = u; E[EN].nx = hd[v]; hd[v] = EN++;
}
int n, h, w, k;
int fa[N], out[N];
int a[N], cnt;
bool vis[N];
int u, v;
int main(){
   // IN;
    SC(n);
    init_edge(n);
    FF(i, 1, n - 1){
        SCC(u, v);
        add_edge(u, v);
    }
    if(n % 2){
        puts("First");
        return 0;
    }
    queue<int>Q;
    Q.push(1);
    vis[1] = 1;
    fa[1] = 0;
    cnt = 1;
    a[1] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int k = hd[u]; ~k; k = E[k].nx){
            int v = E[k].v;
            if(vis[v]) continue;
            ++out[u];
            a[++cnt] = v;
            fa[v] = u;
            Q.push(v);
            vis[v] = 1;
        }
    }
    CL(vis, 0);
    bool ok = 0;
    RR(i, cnt, 1){
        int u = a[i];
        if(vis[u]) continue;
        if(out[fa[u]] > 1){
            ok = 1;
            break;
        }
        vis[u] = 1;
        vis[fa[u]] = 1;
        --out[fa[fa[u]]];
    }
    if(ok) puts("First");
    else puts("Second");
    return 0;
}
