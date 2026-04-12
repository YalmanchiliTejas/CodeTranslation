#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
using namespace std;
const long long MAXN = 500005;
long long dist[MAXN],ways[MAXN],rdist[MAXN],rways[MAXN];
vector<pair<ll,ll> > adj[MAXN];
const long long mod = 1e9+7;
void dijkstra(long long st,long long dist[MAXN],long long ways[MAXN]){
    priority_queue<pair<ll,ll> > pq;
    for(long long i=0;i<MAXN;i++){
        dist[i] = 1e18;
    }
    dist[st] = 0; ways[st] = 1;
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        long long here = pq.top().second;
        ll cst = -pq.top().first;
        pq.pop();
        if(cst > dist[here]) continue;
        for(long long i=0;i<adj[here].size();i++){
            long long there = adj[here][i].first;
            ll w = adj[here][i].second;
            if(dist[there] > dist[here]+w){
                dist[there] = dist[here] + w;
                pq.push(make_pair(-dist[there],there));
                ways[there] = ways[here];
            }
            else if(dist[there] == dist[here] + w){
                ways[there] = (ways[here] + ways[there]) % mod;
            }
        }
    }
}
long long a[MAXN],b[MAXN],c[MAXN];
int main(){
    long long n,m; cin>>n>>m;
    long long s,e; cin>>s>>e;
    for(long long i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        adj[a[i]].push_back(make_pair(b[i],c[i]));
        adj[b[i]].push_back(make_pair(a[i],c[i]));
    }
    dijkstra(s,dist,ways);
    dijkstra(e,rdist,rways);
    long long tot = dist[e];
    long long ans = ways[e] * rways[s];
    ans %= mod;
    if(tot % 2 == 0){
        for(long long i=1;i<=n;i++){
            if(dist[i] == tot/2 && rdist[i] == tot/2){
                long long c = ways[i] * rways[i]; c %= mod;
                c = (c * c) % mod;
                ans = (ans - c + 1000 * mod) % mod;
            }
        }
    }
    double half = tot / 2.0;
    for(long long i=1;i<=m;i++){
        long long u = a[i]; long long v = b[i]; long long w = c[i];
        if(dist[u] + rdist[v] + w == tot){
            if(dist[u] < half && rdist[v] < half){
                long long c = ways[u] * rways[v]; c %= mod;
                c = c * c; c %= mod;
                ans = (ans - c + 1000 * mod) % mod;
            }
        }
        
        swap(a[i],b[i]);
    }
    for(long long i=1;i<=m;i++){
        long long u = a[i]; long long v = b[i]; long long w = c[i];
        if(dist[u] + rdist[v] + w == tot){
            if(dist[u] < half && rdist[v] < half){
                long long c = ways[u] * rways[v]; c %= mod;
                c = c * c; c %= mod;
                ans = (ans - c + 1000 * mod) % mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
