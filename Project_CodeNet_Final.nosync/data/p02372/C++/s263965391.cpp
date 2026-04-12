#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;
struct edge{int to,dis,h;};
vector<edge> S[MAX];
int V;

int DFS(int cur,int from){
    
    int ans=0;
    
    for(int i=0;i<S[cur].size();i++){
        edge &e=S[cur][i];
        if(e.to==from) continue;
        if(e.h==-1) e.h=DFS(e.to,cur);
        ans=max(ans,e.dis+e.h);
    }
    
    return ans;
}

int main(){

    cin>>V;
    for(int i=0;i<V-1;i++){
        int a,b,c;cin>>a>>b>>c;
        S[a].push_back(edge{b,c,-1});
        S[b].push_back(edge{a,c,-1});
    }
    
    for(int i=0;i<V;i++){
        cout<<DFS(i,-1)<<endl;
    }
    
}


