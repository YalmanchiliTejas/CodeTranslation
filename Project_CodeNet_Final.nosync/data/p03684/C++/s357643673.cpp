#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=100005;
int n, fa[maxn], cnt;

struct edge{
    int u, v, cost;
    edge(int cu, int cv, int ccost){u=cu, v=cv, cost=ccost;}
    edge(){}
    bool operator<(const edge &cmp) const{
    	return cost<cmp.cost;
    }
}E[maxn*4];

struct point{
    int x, y, id;
}P[maxn];

bool cmpx(point c1, point c2){return c1.x<c2.x;}
bool cmpy(point c1, point c2){return c1.y<c2.y;}

int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
 
long long Kruskal(){
    for(int i=0;i<=n;i++)fa[i]=i;
    sort(E, E+cnt);
    long long ans=0;
    for(int i=0;i<cnt;i++){
        int fu=Find(E[i].u);
        int fv=Find(E[i].v);
        if(fu!=fv){
            ans+=E[i].cost;
            fa[fu]=fv;
        }
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d", &P[i].x, &P[i].y);
        P[i].id=i;
    }
    cnt=0;
    sort(P, P+n, cmpx);
    for(int i=1;i<n;i++){
        E[cnt++]=edge(P[i-1].id, P[i].id, P[i].x-P[i-1].x);
    }
    sort(P, P+n, cmpy);
    for(int i=1;i<n;i++){
        E[cnt++]=edge(P[i-1].id, P[i].id, P[i].y-P[i-1].y);
    }
    printf("%lld\n", Kruskal());
    return 0;
}