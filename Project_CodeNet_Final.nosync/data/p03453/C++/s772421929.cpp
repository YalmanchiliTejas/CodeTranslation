#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#define MODD 1000000007
#define MAXN 120000
#define ll long long
using namespace std;


vector<pair<int,int>> edges[MAXN+2];


ll dp[2][MAXN+2];
ll mindist[2][MAXN+2];

ll Solve(int u, int dest, bool which) {
    
    
    if (u == dest)
        return dp[which][u]=1;
    
    if (dp[which][u]!=-1)
        return dp[which][u];
    
    ll ans = 0;
    
    for(pair<int,int> vd : edges[u]) {
        int v = vd.first;
        int d = vd.second;
        
        
        if (mindist[which][v]+d == mindist[which][u]) {
            ans += Solve(v,dest,which);
            if (ans >= MODD)
                ans -= MODD;
        }
    }
    dp[which][u]=ans;
    return ans;
    
}


int N,M;

void DoDjikstra(int S, int T, bool which) {
    set<pair<ll,int>> dists;
    dists.insert({0,S});
    
    for(int i=1;i<=N;i++) {
        mindist[which][i]=-1;
        dp[which][i]=-1;
    }
    
    while(!dists.empty()) {
        
        set<pair<ll,int>>::iterator it = dists.begin();
        pair<ll,int> dist_u = *it;
        ll currd = dist_u.first;
        int u = dist_u.second;
        dists.erase(it);
        
        if (mindist[which][u]!=-1)
            continue;
        mindist[which][u]=currd;
        
        for(pair<int,int> vd : edges[u]) {
            int v = vd.first;
            int d = vd.second;
            
            if (mindist[which][v] != -1)
                continue;
            
            dists.insert({currd+d,v});
            
        }
    }
    ll numways = Solve(T,S,which);

    
    
}



int main() {
    cin>>N>>M;
    int S,T;
    cin>>S>>T;
    for(int i=1;i<=M;i++) {
        int U,V,D;
        cin>>U>>V>>D;
        edges[U].push_back({V,D});
        edges[V].push_back({U,D});
    }
    

    
    DoDjikstra(S, T, 0);

    DoDjikstra(T, S, 1);


    

    
    ll numways = dp[0][T]*dp[0][T]%MODD;
    
    // cannot use a vertex u if:
    // mindist[u]*2=mindist[T]
    
    // cannot use an edge (u,v) if:
    // 2*mindist[u] < mindist[T] < 2*(mindist[u]+d(u,v))

    
    for(int u=1;u<=N;u++) {
        if (mindist[0][u]*2==mindist[0][T]) {
            ll curr = dp[0][u]*dp[1][u]%MODD;
            numways -= curr*curr%MODD;
            if (numways < 0)
                numways += MODD;
        }
    }
    
    
    for(int u=1;u<=N;u++) {
        for(pair<int,int> vd : edges[u]) {
            int v = vd.first;
            ll d = vd.second;
            

            
            if (mindist[0][u]+d+mindist[1][v]==mindist[0][T] && 2*mindist[0][u] < mindist[0][T] && 2*mindist[0][u]+2*d > mindist[0][T]) {
                if (dp[0][u]==-1 || dp[1][v]==-1)
                    exit(-1);
                ll curr = dp[0][u]*dp[1][v]%MODD;
                numways -= curr*curr%MODD;
                if (numways < 0)
                    numways += MODD;
            }
            
        }
    }
    
    numways %= MODD;
    
    
    cout << numways << endl;
    
}
