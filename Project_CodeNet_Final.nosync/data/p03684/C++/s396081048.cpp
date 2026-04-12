#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;

const int maxn = 1e5 + 5;

struct Edge{
    int u,v,cost;
    Edge(int u = 0,int v = 0,int cost = 0):u(u),v(v),cost(cost){}
    
}e[maxn * 10];

bool cmp2(Edge a,Edge b){
    return a.cost < b.cost;
}

struct Point{
    int x,y;
    int id;
    Point(int x = 0,int y = 0):x(x),y(y){}
    bool operator < (const Point & rhs)const{
        return x < rhs.x;
    }
}p[maxn];

bool cmp(Point a,Point b){
    return a.y < b.y;
}

int x[maxn],y[maxn];
int fa[maxn];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool s(int x,int y){
    return find(x) == find(y);
}

void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",x + i,y + i);
        p[i].x = x[i];
        p[i].y = y[i];
        p[i].id = i;
    }
    int tot = 0;
    sort(p + 1, p + 1 + n);
    for(int i = 1;i < n;i++){
        int j = i + 1;
        e[tot++] = Edge(p[i].id,p[j].id,p[j].x - p[i].x);
    }
    sort(p + 1,p + 1 + n,cmp);
    for(int i = 1;i < n;i++){
        int j = i + 1;
        e[tot++] = Edge(p[i].id,p[j].id,p[j].y - p[i].y);
    }
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    long long ans = 0;
    sort(e,e + tot,cmp2);
    for(int i = 0;i < tot;i++){
        if(s(e[i].u,e[i].v)) continue;
        Union(e[i].u,e[i].v);
        ans += e[i].cost;
    }
    cout << ans << endl;
    return 0;
}
