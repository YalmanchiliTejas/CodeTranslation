#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long int
#define maxn 300005
#define M 1000000007
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

int n, m, s, t;

struct edge{
    int next, to, len;
    edge(int next, int to, int len) : next(next), to(to), len(len){}
    edge(){}
}e[maxn << 1];

int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
    e[++cnt] = edge(h[x], y, z);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x, z);
    h[y] = cnt;
}

ll d[maxn];
queue<int> spfa;
int tim[maxn];
int ti = 0;
bool vis[maxn];
void SPFA(){
    tim[s] = ++ti;
    d[s] = 0;
    vis[s] = 1;
    spfa.push(s);
    while (!spfa.empty()){
        int x = spfa.front(); spfa.pop();
        erep(i, x){
            int op = e[i].to;
            if (tim[op] != ti || d[op] > d[x] + e[i].len){
                tim[op] = ti;
                d[op] = d[x] + e[i].len;
                if (!vis[op]){
                    vis[op] = 1;
                    spfa.push(op);
                }
            }
        }
        vis[x] = 0;
    }
}

int pre[maxn];
int suf[maxn];
int line[maxn];
bool cmp(int x, int y){
    return d[x] < d[y];
}
bool cmp2(int x, int y){
    return d[y] < d[x];
}

int main(){
    int x, y, z;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    rep(i, 1, m){
        scanf("%d%d%d", &x, &y, &z);
        Add_Edge(x, y, z);
    }
    SPFA();
    rep(i, 1, n) line[i] = i;
    sort(line + 1, line + 1 + n, cmp);
    pre[s] = 1;
    rep(i, 1, n) {
        int x = line[i];
        erep(j, x){
            int op = e[j].to;
            if (d[op] == d[x] - e[j].len) pre[x] = (pre[x] + pre[op]) % M;
        }
    }
    rep(i, 1, n) line[i] = i;
    sort(line + 1, line + 1 + n, cmp2);
    suf[t] = 1;
    rep(i, 1, n){
        int x = line[i];
        erep(j, x){
            int op = e[j].to;
            if (d[op] == d[x] + e[j].len) suf[x] = (suf[x] + suf[op]) % M;
        }
    }
    int ans = 0;
    rep(i, 1, n){
        int x = line[i];
        if (d[x] << 1 == d[t]){
            ll tem = (ll)pre[x] * suf[x] % M;
            ans = (ans + tem * tem % M) % M;
        }
        else {
            erep(j, x){
                int op = e[j].to;
                if (d[op] == d[x] + e[j].len) {
                    if ((d[x] << 1) < d[t] && d[t] < (d[op] << 1)) {
                        ll tem = (ll)pre[x] * suf[op] % M;
                        ans = (ans + tem * tem % M) % M;
                    }
                }
            }
        }
    }
    printf("%lld", (M + (ll)pre[t] * pre[t] % M - ans) % M);
    return 0;
}