#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 200000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
struct Edge{
    int x,y;
    int dis;
    Edge(){}
    Edge(int x,int y,int dis):x(x),y(y),dis(dis){}
    bool operator <(const Edge &rhs)const{
        return dis<rhs.dis;
    }
}edge[N];
int tot;
struct Node{
    int x,y;
}node[N];
int father[N];

bool cmpX(int a,int b){
    return node[a].x<node[b].x;
}
bool cmpY(int a,int b){
    return node[a].y<node[b].y;
}
int Find(int x){
    if(father[x]!=x)
        return father[x]=Find(father[x]);
    return x;
}
int n;
int Kruskal(){
    for(int i=1;i<=n;i++)
        father[i]=i;

    int mst=0;
    sort(edge+1,edge+1+tot);
    for(int i=1;i<=tot;i++){
        int x=Find(edge[i].x);
        int y=Find(edge[i].y);
        if(x!=y){
            mst+=edge[i].dis;
            father[x]=y;
        }
    }
    return mst;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&node[i].x,&node[i].y);

    for(int i=1;i<=n;i++)
        father[i]=i;
    sort(father+1,father+1+n,cmpX);
    for(int i=1;i<n;i++){
        int x=father[i];
        int y=father[i+1];
        int dis=node[y].x-node[x].x;
        edge[++tot]=Edge(x,y,dis);
    }

    for(int i=1;i<=n;i++)
        father[i]=i;
    sort(father+1,father+1+n,cmpY);
    for(int i=1;i<n;i++){
        int x=father[i];
        int y=father[i+1];
        int dis=node[y].y-node[x].y;
        edge[++tot]=Edge(x,y,dis);
    }

    int mst=Kruskal();
    printf("%d\n",mst);

    return 0;
}
