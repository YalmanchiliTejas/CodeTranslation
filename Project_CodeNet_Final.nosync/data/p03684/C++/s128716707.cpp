#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef pair<int,pi> pij;
int root[100010];
int n;
vector<pii> xa,ya;
vector<pi> corx,cory;
priority_queue<pij,vector<pij>,greater<pij> > qu;
map<pi,bool> check;
int fin(int x)
{
    if(root[x]==x) return x;
    return root[x]=fin(root[x]);
}
void join(int x,int y)
{
    int p=fin(x);
    int q=fin(y);
    if(p!=q) root[p]=q;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        root[i]=i;
        int x,y;
        scanf("%d%d",&x,&y);
        if(check[pi(x,y)]==1) continue;
        check[pi(x,y)]=1;
        corx.push_back(pi(x,i));
        cory.push_back(pi(y,i));
    }
    sort(corx.begin(),corx.end());
    sort(cory.begin(),cory.end());
    for(int i=1;i<corx.size();i++)
    {
        qu.push(pij(corx[i].fi-corx[i-1].fi,pi(corx[i].se,corx[i-1].se)));
        qu.push(pij(cory[i].fi-cory[i-1].fi,pi(cory[i].se,cory[i-1].se)));
    }
    int sum=0;
    while(qu.size())
    {
        pij t;
        t=qu.top();
        qu.pop();
        int x,y;
        x=t.se.fi;
        y=t.se.se;
        if(fin(x)==fin(y)) continue;
        sum+=t.fi;
        join(x,y);
    }
    cout<<sum;
}