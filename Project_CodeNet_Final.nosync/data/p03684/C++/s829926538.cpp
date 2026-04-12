#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

struct Node{
    int id,x,y;
}node[100000+10];
struct E{
    int v1,v2,w;
}e[2*100000+20];
int Fa[100000+10];
int cmpx(Node n1,Node n2){
    return n1.x < n2.x;
}
int cmpy(Node n1,Node n2){
    return n1.y < n2.y;
}
int cmp(E e1,E e2){
    return e1.w < e2.w;
}
int fi(int x) {
    if(Fa[x] == x)
        return x;
    return Fa[x] = fi(Fa[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) {
        node[i].id = i;
        scanf("%d%d",&node[i].x,&node[i].y);
    }
    sort(node+1,node+1+n,cmpx);
    int tp = 0;
    for(int i = 2;i <= n;++i) {
        e[tp].v1 = node[i].id;
        e[tp].v2 = node[i-1].id;
        e[tp].w = node[i].x - node[i-1].x;
        tp ++;
    }
    sort(node+1,node+1+n,cmpy);
    for(int i = 2;i <= n;++i) {
        e[tp].v1 = node[i].id;
        e[tp].v2 = node[i-1].id;
        e[tp].w = node[i].y - node[i-1].y;
        tp ++;
    }
    sort(e,e+tp,cmp);
    ll ans = 0;
    for(int i = 1;i <= n;++i)
        Fa[i] = i;
    for(int i = 0;i < tp;++i){
        int v1 = e[i].v1;
        int v2 = e[i].v2;
        int t1 = fi(v1);
        int t2 = fi(v2);
        if(t1 != t2){
            //printf("# %d\n",e[i].w);
            ans += e[i].w;
            Fa[t1] = t2;
        }
    }
    /*for(int i = 0;i < tp;++i){
        printf("%d %d %d\n",e[i].v1,e[i].v2,e[i].w);
    }*/
    printf("%lld\n",ans);
    return 0;
}
