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
int N;
struct node {
    int to,next;
}E[MAXN * 2];
int head[MAXN],sumE,col[MAXN];
bool flag = 0;
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u,int fa) {
    int s = 0;
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	if(v != fa) {
	    dfs(v,u);
	    s += col[v];
	}
    }
    if(s == 0) col[u] = 1;
    if(s >= 2) flag = 1;
}
void Solve() {
    read(N);
    int a,b;
    for(int i = 1 ; i < N ; ++i) {
	read(a);read(b);
	add(a,b);add(b,a);
    }
    dfs(1,0);
    if(col[1] || flag) puts("First");
    else puts("Second");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
