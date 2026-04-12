#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const long long MAXN=500000;  //수정
const long long mod = 1e9+7;
vector<pair<long long, long long> > adj[MAXN];  //first == 도착노드 second 해당엣지의 길이
long long dist[MAXN],rdist[MAXN];
long long n,m;
void dijkstra(long long st,long long dist[MAXN]){
    for(long long i=0; i<MAXN; i++)dist[i]=1e18;   //inf값 그때그째 잘 맞춰서 수정하기
    dist[st]=0;
    priority_queue<pair<long long, long long> > pq;
    pq.push(make_pair(0, st));
    while(!pq.empty()){
        long long cost=-pq.top().first;
        long long here=pq.top().second;
        pq.pop();
        if(dist[here]<cost)continue;
        for(auto node: adj[here]){
            long long there=node.first;
            long long next=cost+node.second;
            if(dist[there]>next){
                dist[there]=next;
                pq.push(make_pair(-next, there));
            }
        }
    }
}
pair<long long,long long> edge[MAXN];
long long wei[MAXN];
vector<pair<long long,long long> > dag[MAXN];
vector<pair<long long,long long> > rdag[MAXN];

void addEdge(long long u,long long v,long long w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

long long S,E;
long long dp1[MAXN];
long long dp2[MAXN];
long long dpEdge1[MAXN],dpEdge2[MAXN];
vector<long long> en[MAXN],ren[MAXN];
long long chk[MAXN],chkedge[MAXN];
long long go(long long cur,long long dp[MAXN],long long ed,vector<pair<long long,long long> > dag[MAXN],long long type){
    if(cur == ed)return 1;
    long long &ret = dp[cur];
    if(ret != -1)return ret;
    ret = 0;
    for(long long i=0;i<dag[cur].size();i++){
        long long nxt = dag[cur][i].first;
        ret = (ret + go(nxt,dp,ed,dag,type)) % mod;
        long long eid;
        if(type == 1){
            eid = en[cur][i];
            if(dpEdge1[eid] == -1) dpEdge1[eid] = go(nxt,dp,ed,dag,type);
        }
        else{
            eid = ren[cur][i];
            if(dpEdge2[eid] == -1)dpEdge2[eid] = go(nxt,dp,ed,dag,type);
        }
        
    }
    return ret;
}
long long getTotal(){
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    memset(dpEdge1,-1,sizeof(dpEdge1));
    memset(dpEdge2,-1,sizeof(dpEdge2));
    long long Sd = go(S,dp1,E,dag,1);
    long long Ed = go(E,dp2,S,rdag,2);
    long long plus1 = (Sd * Ed) % mod;
    long long minus = 0;
    for(long long i=1;i<=n;i++){
        if(chk[i]){
            if(dp1[i] == -1 || dp2[i] == -1) continue;
            long long c = (dp1[i] * dp2[i]) % mod;
            c = (c * c) % mod;
            minus = (minus + c) % mod;
        }
    }
    for(long long i=1;i<=m;i++){
        if(chkedge[i]){
            if(dpEdge1[i] == -1 || dpEdge2[i] == -1) continue;
            long long c = (dpEdge1[i] * dpEdge2[i]) % mod;;
            c = (c * c) % mod;
            minus = (minus + c) %mod;
        }
    }
    return (plus1 - minus + 100000 * mod) % mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    cin>>S>>E;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        edge[i].first = u;
        edge[i].second = v;
        wei[i] = w;
        addEdge(u,v,w);
    }
    dijkstra(S,dist);
    dijkstra(E,rdist);
    if(dist[E] == 1e18){
        cout<<0; exit(0);
    }
    long long tot = dist[E];
    double half = tot/2.0;
    for(long long i=1;i<=m;i++){
        long long u = edge[i].first;
        long long v = edge[i].second;
        long long w = wei[i];
        if(dist[u]+rdist[v] + w == tot){
            if(dist[u] == rdist[u]){
                chk[u] = 1;
            }
            if(dist[v] == rdist[v]){
                chk[v] = 1;
            }
            
            if(dist[u] < half && dist[v] > half){
                chkedge[i] = 1;
            }
            
            dag[u].push_back(make_pair(v,w)); en[u].push_back(i);
            rdag[v].push_back(make_pair(u,w)); ren[v].push_back(i);
            
        }
        else if(dist[v]+rdist[u]+w == tot){
            if(dist[u] == rdist[u]){
                chk[u] = 1;
            }
            if(dist[v] == rdist[v]){
                chk[v] = 1;
            }
            
            if(dist[v] < half && dist[u] > half){
                chkedge[i] = 1;
            }
            
            dag[v].push_back(make_pair(u,w)); en[v].push_back(i);
            rdag[u].push_back(make_pair(v,w)); ren[u].push_back(i);
        }
    }
    long long ans = getTotal();
    cout<<ans;
    
    return 0;
}

