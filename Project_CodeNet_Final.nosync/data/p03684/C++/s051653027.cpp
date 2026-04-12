#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
    int x,y,cost;
};

struct pct
{
    int x,y,ind;
};

bool cmp1(pct a, pct b)
{
    return a.x<b.x;
}

bool cmp2(pct a, pct b)
{
    return a.y<b.y;
}

bool cmp(edge a, edge b)
{
    return a.cost<b.cost;
}

pct P[100005];
vector<edge> Edg;
int Pa[100005],Sz[100005];

int parent(int x)
{
    int cx=x;
    while(Pa[x]!=0)
        x=Pa[x];

    while(Pa[cx]!=0)
    {
        int aux=Pa[cx];
        Pa[cx]=x;
        cx=aux;
    }
    return x;
}

bool unite(int x, int y)
{
    x=parent(x);
    y=parent(y);

    if(x==y)
        return 0;

    if(Sz[x]>=Sz[y])
    {
        Sz[x]+=Sz[y];
        Pa[y]=x;
    }
    else
    {
        Sz[y]+=Sz[x];
        Pa[x]=y;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>P[i].x>>P[i].y;
        P[i].ind=i;
        Sz[i]=1;
    }

    sort(P+1,P+n+1,cmp1);
    for(int i=2; i<=n; i++)
        Edg.push_back({P[i].ind,P[i-1].ind,P[i].x-P[i-1].x});

    sort(P+1,P+n+1,cmp2);
    for(int i=2; i<=n; i++)
        Edg.push_back({P[i].ind,P[i-1].ind,P[i].y-P[i-1].y});

    sort(Edg.begin(),Edg.end(),cmp);

    long long rez=0;
    for(auto edg:Edg)
    {
        if(unite(edg.x,edg.y))
            rez+=edg.cost;
    }

    cout<<rez<<"\n";
    return 0;
}
