#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

vector <pair<int, int> > a, b;
int F[N];
struct Edge
{
    int u, v, w;
}edge[N << 4];
int tol;
void addedge(int u,int v,int w)
{
    edge[tol].u=u;
    edge[tol].v=v;
    edge[tol++].w=w;
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(F[x]==-1) return x;
    else return F[x]=find(F[x]);
}
long long Kruskal(int n)
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    int cnt=0;
    long long ans=0;
    for(int i=0;i<tol;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            ans+=w;
            F[t1]=t2;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    if(cnt<n-1) return -1;
    else return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, i});
        b.push_back({y, i});
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) { return x.first < y.first;});
    sort(b.begin(), b.end(), [](pair<int, int> x, pair<int, int> y) { return x.first < y.first;});
    
    for(int i = 1; i < n; ++i)
    {
        addedge(a[i - 1].second, a[i].second, a[i].first - a[i - 1].first);
        addedge(b[i - 1].second, b[i].second, b[i].first - b[i - 1].first);
    }
    
    cout << Kruskal(n) << endl;
    
    return 0;
}