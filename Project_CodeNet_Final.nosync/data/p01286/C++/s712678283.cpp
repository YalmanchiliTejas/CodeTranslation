#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF 1000
using namespace std;

struct edge{int to,cap,rev;};

vector<edge> g[310];
bool used[310];

void add_edge(int from, int to, int cap){
    g[from].push_back((edge){to,cap,(int)g[to].size()});
    g[to].push_back((edge){from,0,(int)g[from].size()-1});
}

int dfs(int v,int t,int f){
    if(v==t){
        return f;
    }
    used[v]=true;
    for(int i=0;i<g[v].size();i++){
        edge &e=g[v][i];
        if(!used[e.to]&&e.cap>0){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow=0;
    for(;;){
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
int main(){
    int h,w,m,c,nw,nc,nm,a,b;
    scanf("%d %d %d %d %d %d %d",&h,&w,&c,&m,&nw,&nc,&nm);
    while(h>=0||w>=0||c>=0||m>=0||nc>=0||nw>=0&&nm>=0){
        for(int i=0;i<310;i++){
            g[i].clear();
        }
        for(int i=1;i<=h;i++){
            add_edge(0,i,1);
            add_edge(i,101,1);
        }
        for(int i=51;i<=50+w;i++){
            add_edge(i,i+51,1);
            add_edge(i+51,203,1);
        }
        add_edge(101,152,nw);
        for(int i=153;i<=152+c;i++){
            add_edge(152,i,1);
            add_edge(i,i+51,1);
            add_edge(i+51,305,1);
        }
        add_edge(203,254,nc);
        for(int i=255;i<=254+m;i++){
            add_edge(254,i,1);
            add_edge(i,306,1);
        }
        add_edge(305,306,nm);
        for(int i=0;i<w;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                add_edge(b,51+i,1);
            }
        }
        for(int i=0;i<c;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                add_edge(101+b,153+i,1);
            }
        }
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                add_edge(b+203,255+i,1);
            }
        }
        printf("%d\n",max_flow(0,306));
        scanf("%d %d %d %d %d %d %d",&h,&w,&c,&m,&nw,&nc,&nm);
    }
}
