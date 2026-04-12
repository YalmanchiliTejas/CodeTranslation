#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 +c - '0';
	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N;
int x[MAXN],y[MAXN];
int id[MAXN],cnt,fa[MAXN];
struct node {
    int u,v,c;
}E[MAXN * 10];
int getfa(int u) {
    return fa[u] == u ? u : fa[u] = getfa(fa[u]);
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(x[i]);read(y[i]);}
    for(int i = 1 ; i <= N ; ++i) id[i] = i;
    sort(id + 1,id + N + 1,[](int a,int b) {return x[a] < x[b];});
    for(int i = 1 ; i < N ; ++i) {
	E[++cnt] = (node){id[i],id[i + 1],x[id[i + 1]] - x[id[i]]};
    }
    for(int i = 1 ; i <= N ; ++i) id[i] = i;
    sort(id + 1,id + N + 1,[](int a,int b) {return y[a] < y[b];});
    for(int i = 1 ; i < N ; ++i) {
	E[++cnt] = (node){id[i],id[i + 1],y[id[i + 1]] - y[id[i]]};
    }
    sort(E + 1,E + cnt + 1,[](node a,node b){return a.c < b.c;});
    for(int i = 1 ; i <= N ; ++i) fa[i] = i;
    int ans = 0;
    for(int i = 1 ; i <= cnt ; ++i) {
	if(getfa(E[i].u) != getfa(E[i].v)) {
	    ans += E[i].c;
	    fa[getfa(E[i].u)] = getfa(E[i].v);
	}
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
