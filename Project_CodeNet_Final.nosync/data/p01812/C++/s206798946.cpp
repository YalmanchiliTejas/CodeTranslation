#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<16,INF=1<<30;

vector<int> G[MAX];
int M,dis[MAX];

void BFS(){
    dis[(1<<M)-1]=0;
    queue<int> Q;
    Q.push((1<<M)-1);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(dis[to]==INF){
                dis[to]=dis[u]+1;
                Q.push(to);
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>M>>K;
    vector<int> D(100,-1),revD(M);
    for(int i=0;i<(1<<M);i++) dis[i]=INF;
    vector<vector<int>> to(N,vector<int>(K));
    for(int i=0;i<M;i++){
        int a;cin>>a;
        a--;
        D[a]=i;
        revD[i]=a;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>to[i][j];
            to[i][j]--;
        }
    }
    
    for(int bit=(1<<M)-1;bit>0;bit--){
        for(int a=0;a<K;a++){
            int ne=0;
            for(int i=0;i<M;i++){
                if(!(bit&(1<<i))) continue;
                int t=to[revD[i]][a];
                if(D[t]==-1) continue;
                ne|=(1<<D[t]);
            }
            G[bit].push_back(ne);
        }
    }
    
    BFS();
    
    cout<<dis[0]<<endl;
    
    
    
}


