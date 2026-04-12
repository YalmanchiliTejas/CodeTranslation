#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=4003,INF=1<<30;
ll dis[MAX][MAX];
vector<pair<int,ll>> G[MAX];
int V;

struct edge{int from,to;ll dis;};

bool compare(edge a,edge b){
    return a.dis<b.dis;
}

int par[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)) par[root(b)]=root(a);
}

bool check(int a,int b){
    return root(a)==root(b);
}

void BFS(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dis[i][j]=-1;
        }
        dis[i][i]=0;
        queue<int> Q;
        Q.push(i);
        
        while(!Q.empty()){
            int a=Q.front();Q.pop();
            for(int k=0;k<G[a].size();k++){
                int b=G[a][k].first;
                ll c=G[a][k].second;
                
                if(dis[i][b]!=-1) continue;
                
                dis[i][b]=max(dis[i][a],c);
                Q.push(b);
            }
        }
    }
}


int main(){
    
    int E;cin>>V>>E;
    vector<edge> S(E);
    for(int i=0;i<E;i++){
        int a,b;
        ll c;cin>>a>>b>>c;
        a--;b--;
        S[i]={a,b,c};
    }
    
    sort(all(S),compare);
    
    init(V);
    
    ll sum=0;
    
    for(int i=0;i<E;i++){
        int a=S[i].from,b=S[i].to;
        ll c=S[i].dis;
        if(check(a,b)) continue;
        unite(a,b);
        sum+=c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    
    BFS();
    
    int Q;cin>>Q;
    while(Q){
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<sum-dis[a][b]<<endl;
        
        Q--;
    }
    
}

