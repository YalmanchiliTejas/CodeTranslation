#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 1e9;
struct Ford_fulkerson{
    struct edge{int to,cap,rev;};
    int n;
    vector<vector<edge> > graph;
    vector<int> vis;
    
    Ford_fulkerson(int _n):n(_n),graph(n),vis(n){}
    
    void addEdge(int from,int to,int cap){
        graph[from].push_back((edge){to,cap,(int)graph[to].size()});
        graph[to].push_back((edge){from,0,(int)graph[from].size()-1});
    }
    int dfs(int v,int t,int f){
        if(v==t)return f;
        vis[v]=true;
        for(int i=0;i<(int)graph[v].size();i++){
            edge& e = graph[v][i];
            if(!vis[e.to]&&e.cap>0){
                int d = dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    graph[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s,int t){
        int flow=0;
        for(;;){
            for(int i=0;i<n;i++)vis[i]=false;
            int f = dfs(s,t,INF);
            if(f==0)return flow;
            flow+=f;
        }
    }
    
};

int main(){
    int H,W,C,M,Nw,Nc,Nm;
    while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm){
        if(H==-1)break;
        int s = 0;
        int t = H+(W*2)+(C*2)+(M*2)+1;
        int nw1 = t+1,nw2=nw1+1;
        int nc1 = nw2+1,nc2=nc1+1;
        int nm1 = nc2+1,nm2=nm1+1;
        Ford_fulkerson ff(nm2+10);

        for(int i=1;i<=W;i++){
            int n;
            cin >> n;
            for(int j=0;j<n;j++){
                int k;
                cin >> k;
                ff.addEdge(k,H+i,1);//勇者ー＞戦士
            }
        }
        for(int i=1;i<=C;i++){
            int n;
            cin >> n;
            for(int j=0;j<n;j++){
                int k;
                cin >> k;
                ff.addEdge(H+W+k,H+(2*W)+i,1);//戦士ー＞僧侶
            }
        }
        for(int i=1;i<=M;i++){
            int n;
            cin >> n;
            for(int j=0;j<n;j++){
                int k;
                cin >> k;
                ff.addEdge(H+(2*W)+C+k,H+(2*W)+(2*C)+i,1);//僧侶ー＞魔法使い
            }
        }

        for(int i=1;i<=H;i++){
            ff.addEdge(s,i,1);//s->勇者
            ff.addEdge(i,nw1,1);//勇者ー＞戦士選ばない
        }
        ff.addEdge(nw1,nw2,Nw);//戦士選ばない組がNw組
        for(int i=1;i<=W;i++){
            ff.addEdge(H+i,H+W+i,1);//選抜
            ff.addEdge(H+W+i,nc1,1);//戦士ー＞僧侶選ばない
        }
        ff.addEdge(nc1,nc2,Nc);//僧侶選ばない組がNc組
        for(int i=1;i<=C;i++){
            ff.addEdge(nw2,H+(2*W)+i,1);//戦士選ばないー＞僧侶
            ff.addEdge(H+(2*W)+i,H+(2*W)+C+i,1);//選抜
            ff.addEdge(H+(2*W)+C+i,nm1,1);//僧侶ー＞魔法使い選ばない
        }
        ff.addEdge(nm1,nm2,Nm);//魔法使い選ばない組がNm組
        for(int i=1;i<=M;i++){
            ff.addEdge(nc2,H+(2*W)+(2*C)+i,1);//僧侶選ばないー＞魔法使い
            ff.addEdge(H+(2*W)+(2*C)+i,H+(2*W)+(2*C)+M+i,1);//選抜
            ff.addEdge(H+(2*W)+(2*C)+M+i,t,1);//魔法使いー＞t
        }
        ff.addEdge(nm2,t,Nm);

        cout << ff.maxFlow(s,t) << endl;
    }
    return 0;
}
