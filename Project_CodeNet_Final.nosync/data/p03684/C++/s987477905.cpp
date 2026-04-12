#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ll long long
const int INF = 1e9 + 7;

using namespace std;

#define MAX_V 100000
typedef pair<int,int> P;
struct edge{
    int to,cost;
};
int V;
vector<edge> G[MAX_V];
bool used[MAX_V];

//priority_queue使用版，0(ElogV)
int prim(){
    priority_queue<P, vector<P>, greater<P>> que;
    memset(used, 0, sizeof(used));
    que.push(P(0,0));
    ll res = 0;
    while(!que.empty()) {
        int cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = 1;
        //cout << "v:" << v << " cst:" << cst << endl;
        res += cst;
        REP(i,G[v].size()) que.push(P(G[v][i].cost, G[v][i].to));
    }
    return res;
}

int main(){
    cin.tie(0), ios::sync_with_stdio(false);
    cin >> V;
    vector<pair<int,int>> vx(V),vy(V);
    REP(i,V){
        cin >> vx[i].first >> vy[i].first;
        vx[i].second = vy[i].second = i;
    }
    sort(vx.begin(),vx.end());
    REP(i,V-1){
        G[vx[i].second].push_back(edge{vx[i+1].second,vx[i+1].first-vx[i].first});
        G[vx[i+1].second].push_back(edge{vx[i].second,vx[i+1].first-vx[i].first});
    }
    sort(vy.begin(),vy.end());
    REP(i,V-1){
        G[vy[i].second].push_back(edge{vy[i+1].second,vy[i+1].first-vy[i].first});
        G[vy[i+1].second].push_back(edge{vy[i].second,vy[i+1].first-vy[i].first});
    }

    /*
    REP(i,V){
        REP(j,G[i].size()){
            cout << "G[" << i << "][" << G[i][j].to << "]:" << G[i][j].cost << "\n";
        }
    }
    */

    cout << prim() << "\n";
    return 0;
}
