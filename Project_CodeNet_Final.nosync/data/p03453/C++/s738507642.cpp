#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

struct edge{

long long f,s;

};

int n,m;
int s,t;
int i,j;
vector<pair<int,long long> > v[100001];

long long vis[100001],dp1[100001], dp2[100001];
long long cnt1[100001],cnt2[100001];


void dijk( int src,long long cnt[], long long dist[])
{
    int i;
    set<pair<long long,int> > s;
    set<pair<long long,int> >::iterator it;
    s.insert(make_pair(0,src));
     while(!s.empty())
    {   it=s. begin();
        long long a=it->first;
        int b=it->second; 
        dist[b]=a;
        s.erase(s.begin());
        vis[b]=1;
        for(i=0;i<v[b].size();i++)
        {
            if(vis[v[b][i].first]==0&&(dist[b]+v[b][i].second<=dist[v[b][i].first]))
            {
                if(dist[v[b][i].first]!=1e18)
                s.erase(make_pair(dist[v[b][i].first],v[b][i].first));
                
                if(dist[b]+v[b][i].second==dist[v[b][i].first])
                {
                    cnt[v[b][i].first]+= cnt[b]; 
                    if(cnt[v[b][i].first]>=mod)cnt[v[b][i].first]-=mod;
                    s.insert(make_pair(dist[v[b][i].first],v[b][i].first));
                    continue;
                }
                dist[v[b][i].first]=dist[b]+v[b][i].second;
                cnt[v[b][i].first]= cnt[b];
                if(cnt[v[b][i].first]>=mod)cnt[v[b][i].first]-=mod;
                
                s.insert(make_pair(dist[v[b][i].first],v[b][i].first));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    cin>>s>>t;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    fill(dp1,dp1+n+1, 1e18);
    fill(dp2,dp2+n+1, 1e18);
    
    
    cnt1[s]=1, cnt2[t]=1;
    dp1[s]=0;
    dijk(s,cnt1,dp1);
    fill(vis,vis+n+1, 0);
    
    dp2[t]=0;
    dijk(t,cnt2,dp2);
    
    long long total= (cnt1[t]*cnt1[t])%mod;
    
    for(i=1;i<=n;i++)
    {   
        if(2*dp1[i]==dp1[t] && 2*dp2[i]== dp1[t])
        {
            long long temp = (cnt1[i]*cnt2[i])%mod;
            temp = (temp*temp)%mod;
            total = (total - temp + mod)%mod;
        }
        
    }
    
    
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            long long t1= dp1[i];
            long long t2= dp2[v[i][j].first];
            long long c= v[i][j].second;
            if( 2*t1<dp1[t] && 2*t2<dp1[t] && t1+t2+c== dp1[t])
            {
                long long temp = (cnt1[i]*cnt2[v[i][j].first])%mod;
                temp = (temp*temp)%mod;
                total = (total - temp + mod)%mod;
            }
            
        }
    }
    assert(total>=0);
    cout<<total;
    return 0;
}
