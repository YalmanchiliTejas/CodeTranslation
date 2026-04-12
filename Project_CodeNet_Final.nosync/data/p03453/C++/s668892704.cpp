#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <stack>
#include <functional>
#include <bitset>
#include <math.h>
using namespace std;
#define ll long long

const int N = 1e5+3;
const int mod = (int)1e9+7;
vector<pair<int,int> > adj[N];
const ll inf = 1e17;
int add(int x,int y) {
    int ret = (x+y)%mod;
    if(ret<0) {
        ret += mod;
    }
    return ret;
}
int mul(int x,int y) {
    return (ll)x*y%mod;
}
int mypow(int x,int c) {
    int ret = 1;
    while(c>0) {
        if(c&1) {
            ret = mul(ret,x);
        }
        c/=2;
        x = mul(x,x);
    }
    return ret;
}

ll sToNode[N], sNum[N];
ll tToNode[N], tNum[N];

void dijkstra(ll *dist, ll *num,int stNode,int n) {
    for(int i=1;i<=n;++i) {
        dist[i] = inf;
    }
    dist[stNode] = 0;
    num[stNode] = 1;
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    pq.push(make_pair(0,stNode));
    while(!pq.empty()) {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d!= dist[node]) {
            continue;
        }
        for(int i=0;i<(int)adj[node].size();++i) {
            int w = adj[node][i].second;
            int nextNode = adj[node][i].first;
            if(dist[nextNode]>= w + d) {
                if(dist[nextNode]== w+ d) {
                    num[nextNode] = add(num[nextNode], num[node]);
                } else {
                    num[nextNode] = num[node];
                    dist[nextNode] = w + d;
                    pq.push(make_pair(dist[nextNode],nextNode));
                }
            }
        }
    }
}
void solve() {
    int n,m;
    scanf("%d %d",&n,&m);
    int s,t;
    scanf("%d %d",&s,&t);
    for(int i=0;i<m;++i) {
        int u,v,d;
        scanf("%d %d %d",&u,&v,&d);
        adj[u].push_back(make_pair(v,d));
        adj[v].push_back(make_pair(u,d));
    }
    dijkstra(sToNode,sNum,s,n);
    dijkstra(tToNode,tNum,t,n);
    assert(sToNode[t] == tToNode[s]);
    ll totalDist =  sToNode[t];
    ll ret = mul(sNum[t],sNum[t]);
    for(int node = 1;node<=n;++node) {
        if(node==t || sToNode[node] + tToNode[node] != totalDist) {
            continue;
        }
        ///special case
        if(sToNode[node]*2 == totalDist) {
            int k = mul(sNum[node],tNum[node]);
            k = mul(k,k);
            ret = add(ret, -k);
        }
        //edge collision
        for(int j = 0;j<(int)adj[node].size();++j) {
            int v = adj[node][j].first;
            int w = adj[node][j].second;
            if(sToNode[v] + tToNode[v] != totalDist) {
                continue;
            }
            if(sToNode[node] + w == sToNode[v]) {
                ll a = sToNode[node], b = tToNode[v];
                if( (a<=b && b<a+w) || (b<=a && a<b+w)) {
                    int k = mul(sNum[node],tNum[v]);
                    k = mul(k,k);
                    ret = add(ret,-k);
                }
            }
        }
    }
    cout<<ret<<endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    solve();
}