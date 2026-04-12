#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<pair<int,int> > >adj;
int dis[2][100005];
int ans[2][100004];
const int mod=1e9+7;

void dikstra(int ver,int x)
{
    dis[x][ver]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qq;
    qq.push({0,ver});
    ans[x][ver]=1;
    while(!qq.empty())
    {
        pair<int,int>p=qq.top();
        qq.pop();
        if(dis[x][p.second]<p.first)
            continue;
        for(auto i:adj[p.second])
        {
            if(dis[x][i.first]>p.first+i.second)
            {
                dis[x][i.first]=p.first+i.second;
                qq.push({dis[x][i.first],i.first});
                ans[x][i.first]=ans[x][p.second];
            }
            else if(dis[x][i.first]==p.first+i.second)
            {
                ans[x][i.first]+=ans[x][p.second];
                ans[x][i.first]%=mod;
            }
        }
    }
}

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int s,t;
    cin>>s>>t;
    int x,y,z;
    vector<pair<pair<int,int> ,int> >pp;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        pp.push_back({{x,y},z});
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    fill_n(&dis[0][0],2*100005,1e17);
    dikstra(s,0);
    dikstra(t,1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[0][i]+dis[1][i]==dis[0][t])
        {
            if(dis[0][i]==dis[1][i])
            {
                int xx=(ans[0][i]*ans[1][i])%mod;
                res+=(xx*xx)%mod;
                res%=mod;
            }
        }
    }

    for(auto i:pp)
    {
        x=i.first.first;
        y=i.first.second;
        int mn=min(dis[0][x],dis[1][y]);
        int mx=max(dis[0][x],dis[1][y]);
        if(dis[0][x]+dis[1][y]+i.second==dis[0][t])
        {
            if(mn+i.second>mx)
            {
                int xx=(ans[0][x]*ans[1][y])%mod;
                res+=(xx*xx)%mod;
                res%=mod;
            }
        }
        x=i.first.second;
        y=i.first.first;
        mn=min(dis[0][x],dis[1][y]);
        mx=max(dis[0][x],dis[1][y]);
        if(dis[0][x]+dis[1][y]+i.second==dis[0][t])
        {
            if(mn+i.second>mx)
            {
                int xx=(ans[0][x]*ans[1][y])%mod;
                res+=(xx*xx)%mod;
                res%=mod;
            }
        }        
    }

    int tot=(ans[0][t]*ans[1][s])%mod;
    tot+=mod-res;
    tot%=mod;
    cout<<tot;

} 
