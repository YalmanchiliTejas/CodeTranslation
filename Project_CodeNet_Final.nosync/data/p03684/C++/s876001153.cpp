#include <stdio.h>
#include <vector>
#include <algorithm>

#define minn(a,b) (a<=b?a:b)
#define abss(a,b) (a>=b?a-b:b-a)

int t1,t2,t3;

int n;
int x[100005];
int y[100005];

std::pair<int,int> xi[100005];  // {x, id}
std::pair<int,int> yi[100005];  // {y, id}

// {cost,{start,end}}
std::vector<std::pair<int,std::pair<int,int> > > g;

void push(int u,int v)
{
    t2=abss(x[u],x[v]);
    t3=abss(y[u],y[v]);
    //printf("%d %d has %d %d\n",u,v,t2,t3);
    g.push_back({minn(t2,t3),{u,v}});
}

int lv[100005];
int up[100005];

int get(int u)
{
    if (up[u]!=up[up[u]]) return up[u]=get(up[u]);
    return up[u];
}

long long ans=0;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",x+i,y+i);
        xi[i]={x[i],i};
        yi[i]={y[i],i};
        up[i]=i;
    }
    // get all relevant edges
    std::sort(xi,xi+n);
    std::sort(yi,yi+n);
    for (int i=1; i<n; i++) {
        push(xi[i-1].second,xi[i].second);
        push(yi[i-1].second,yi[i].second);
    }
    // kruskal
    std::sort(g.begin(),g.end());
    for (std::pair<int,std::pair<int,int> > e:g) {
        t1=get(e.second.first);
        t2=get(e.second.second);
        //printf("weird %d\n",e.first);
        if (t1!=t2) {
            ans+=e.first;
            //printf("use %d %d\n",e.second.first,e.second.second);
            if (lv[t1]<lv[t2]) up[t1]=t2;
            else if (lv[t1]>lv[t2]) up[t2]=t1;
            else {
                up[t1]=t2;
                lv[t2]++;
            }
        }
    }
    printf("%lld",ans);
}
