#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll froms[100005],fromt[100005],disfroms[100005],disfromt[100005],p=1e9+7;
vector<pair<int,ll> >adj[100005];
int n,m,s,t;
int main(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;++i){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    priority_queue<pair<ll,int> >pq;
    memset(disfroms,-1,sizeof disfroms);
    disfroms[s]=0;
    pq.push({0,s});
    froms[s]=1;
    while(!pq.empty()){
        int x=pq.top().second;ll w=-pq.top().first;
        pq.pop();
        if(disfroms[x]<w)continue;
        froms[x]%=p;
        for(auto y:adj[x]){
            int nxt=y.first;ll nw=w+y.second;
            if(disfroms[nxt]==-1||disfroms[nxt]>nw){
                disfroms[nxt]=nw;
                froms[nxt]=froms[x];
                pq.push({-nw,nxt});
                continue;
            }
            if(disfroms[nxt]<nw)continue;
            froms[nxt]+=froms[x];
            froms[nxt]%=p;
        }
    }

    memset(disfromt,-1,sizeof disfromt);
    disfromt[t]=0;
    pq.push({0,t});
    fromt[t]=1;
    while(!pq.empty()){
        int x=pq.top().second;ll w=-pq.top().first;
        pq.pop();
        if(disfromt[x]<w)continue;
        fromt[x]%=p;
        for(auto y:adj[x]){
            int nxt=y.first;ll nw=w+y.second;
            if(disfromt[nxt]==-1||disfromt[nxt]>nw){
                disfromt[nxt]=nw;
                fromt[nxt]=fromt[x];
                pq.push({-nw,nxt});
                continue;
            }
            if(disfromt[nxt]<nw)continue;
            fromt[nxt]+=fromt[x];
            fromt[nxt]%=p;
        }
    }

    long long ans=froms[t]*froms[t];
    ans%=p;
//    cout<<ans<<endl;
    for(int i=1;i<=n;++i){
        froms[i]%=p;
        fromt[i]%=p;
        if(disfroms[i]+disfromt[i]!=disfroms[t])continue;
        if(2*disfroms[i]!=disfroms[t])continue;
        ans%=p;if(ans<0)ans+=p;
        ans-=(((froms[i]*froms[i])%p)*((fromt[i]*fromt[i])%p))%p;
        if(ans<0)ans+=p;
    }
//    cout<<ans<<endl;
    for(int i=1;i<=n;++i){
        for(auto x:adj[i]){
            int j=x.first;ll d=x.second;
            if(disfroms[i]+disfromt[j]+d!=disfroms[t])continue;
//            cout<<i<<" "<<j<<endl;
            if(disfromt[j]<disfroms[j]&&disfroms[i]<disfromt[i]){
                ans%=p;if(ans<0)ans+=p;
                ans-=(((froms[i]*froms[i])%p)*((fromt[j]*fromt[j])%p))%p;
                if(ans<0)ans+=p;
            }
        }
    }
    cout<<ans<<endl;

}
