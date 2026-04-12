//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
struct node {
    int x,y,id;
    node(int _x = 0,int _y = 0,int c = 0):x(_x),y(_y),id(c) {};
} f[maxn],g[maxn * 2];

bool cmp1(const node &a,const node &b) {
    return a.x < b.x;
}

bool cmp2(const node &a,const node &b) {
    return a.y < b.y;
}

bool cmp3(const node &a,const node &b) {
    return a.id < b.id;
}

int p[maxn];

int ff(int x){
    if(p[x] != x) p[x] = ff(p[x]);
    return p[x];
}

LL build(int n,int m) {
    int i,u,v;
    LL s = 0;
    for(i = 1;i <= n; i++) p[i] = i;
    sort(g,g + m,cmp3);
    for(i = 0;i < m; i++){
        u = ff(g[i].x);
        v = ff(g[i].y);
        if(u != v){
            s += g[i].id;
            p[u] = v;
        }
    }
    return s;
}

int main() {
    int n,i,m;
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        scanf("%d%d",&f[i].x,&f[i].y);
        f[i].id = i + 1;
    }
    m = 0;
    sort(f,f + n,cmp1);
    for(i = 1; i < n; i++) g[m++] = node(f[i].id,f[i - 1].id,f[i].x - f[i - 1].x);
    sort(f,f + n,cmp2);
    for(i = 1; i < n; i++) g[m++] = node(f[i].id,f[i - 1].id,f[i].y - f[i - 1].y);
    printf("%lld\n",build(n,m));
    return 0;
}
