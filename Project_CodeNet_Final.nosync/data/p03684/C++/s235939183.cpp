#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+100;
int n,ans;
class edge
{
    public:
    int f,t,w;
    edge(int f,int t,int w):f(f),t(t),w(w){}
};
class ufind
{
    vector<int> f,r;
    public:
    ufind(int n)
    {
        f.resize(N);
        r.assign(N,1);
        for(int i=1;i<=n;++i) f[i]=i;
    }
    int find(int x)
    {
        if (x==f[x]) return x;
        else return f[x]=find(f[x]);
    }
    bool unite(int x,int y)
    {
        x=find(x);y=find(y);
        if (x==y) return false;
        if (r[x]<r[y]) swap(x,y);
        f[y]=x;
        if (r[x]==r[y]) r[x]++;
        return true;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    vector<pair<int,int>> x,y;
    for(int i=1;i<=n;++i)
    {
        int xx,yy;
        cin>>xx>>yy;
        x.push_back(make_pair(xx,i));
        y.push_back(make_pair(yy,i));
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<edge> e;
    for(int i=1;i<n;++i) 
    {
        e.push_back(edge(x[i-1].second,x[i].second,x[i].first-x[i-1].first)); 
        e.push_back(edge(y[i-1].second,y[i].second,y[i].first-y[i-1].first)); 
    }
    sort(e.begin(),e.end(),[](const edge &a,const edge &b){return a.w<b.w;});
    ufind s(n);
    for(auto i:e)
        if(s.unite(i.f,i.t)) ans+=i.w;
    cout<<ans<<endl;
    return 0;
}