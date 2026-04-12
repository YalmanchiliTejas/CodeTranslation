#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pll;
const int maxn=100005;
int n,m,f[maxn];
struct point {
    int x,y,id;
} p[maxn];
bool cmp1(point p1,point p2) {
    return p1.x<p2.x;
}
bool cmp2(point p1,point p2) {
    return p1.y<p2.y;
}
inline void init() {
    for (int i=0;i<n;++i)
        f[i]=i;
}
int F(int x) {
    return x==f[x]?x:f[x]=F(f[x]);
}
inline void U(int a,int b) {
    f[F(a)]=F(b);
}
struct edge {
    int u,v,w;
    edge(){}
    edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator<(const edge &rhs)const{
        return w<rhs.w;
    }
} e[maxn<<1];
int main()
{
    scanf("%d",&n);
    init();
    for (int i=0;i<n;++i) {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p,p+n,cmp1);
    for (int i=0;i<n-1;++i)
        e[i]=edge(p[i].id,p[i+1].id,abs(p[i].x-p[i+1].x));
    sort(p,p+n,cmp2);
    for (int i=0;i<n-1;++i)
        e[i+n-1]=edge(p[i].id,p[i+1].id,abs(p[i].y-p[i+1].y));
    m=2*n-2;
    sort(e,e+m);
    long long res=0;
    for (int i=0;i<m;++i)
        if (F(e[i].u)!=F(e[i].v)) {
            U(e[i].u,e[i].v);
            res+=1LL*e[i].w;
        }
    cout<<res<<endl;
    return 0;
}
