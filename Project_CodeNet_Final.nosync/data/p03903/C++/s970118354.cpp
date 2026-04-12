#include<bits/stdc++.h>
using namespace std;

using Weight=long long;
struct Edge{
    int from,to;
    Weight c;
};
bool operator<(const Edge &lhs,const Edge &rhs){
    return lhs.c<rhs.c;
}
bool operator>(const Edge &lhs,const Edge &rhs){
    return lhs.c>rhs.c;
}

using Edges=vector<Edge>;
using Graph=vector<Edges>;

Graph MST(int n,Graph& g){
    vector<int> used(n,false);
    priority_queue<Edge,vector<Edge>,greater<>> que;
    que.push({-1,0,0});
    Graph res(n);
    while(!que.empty()){
        Edge ret=que.top();
        que.pop();
        int f=ret.from;
        int v=ret.to;
        Weight c=ret.c;
        if(used[v]) continue;
        used[v]=true;
        if(f!=-1){
            res[f].push_back(Edge{f,v,c});
            res[v].push_back(Edge{v,f,c});
        }
        for(int i=0;i<g[v].size();i++){
            que.push(g[v][i]);
        }
    }
    return res;
}
int main(){
    int n,m;;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int a,b;
        Weight c;
        cin>>a>>b>>c;
        a--,b--;
        g[a].push_back(Edge{a,b,c});      
        g[b].push_back(Edge{b,a,c});
    }
    
    Graph mst=MST(n,g);
    Edges edges;
    for(int i=0;i<mst.size();i++){
        for(int j=0;j<mst[i].size();j++) edges.push_back(mst[i][j]);
    }
    sort(edges.begin(),edges.end(),greater<>());
    
    auto adder=[](Weight lhs,Edge& e){
        return lhs+e.c;
    };
    Weight sum=accumulate(edges.begin(),edges.end(),0LL,adder)/2;
    
    vector<vector<Weight>> sc(n,vector<Weight>(n,0));
    vector<vector<int>> slash(n,vector<int>(n,false));

    function<void(int,int,vector<int>&)> dfs=[&](int v,int pre,vector<int>& vs){
        vs.push_back(v);
        for(int i=0;i<mst[v].size();i++){
            if(mst[v][i].to!=pre && !slash[v][mst[v][i].to]){
                dfs(mst[v][i].to,v,vs);
            }
        }
        return;
    };

    for(int i=0;i<edges.size();i++){
        int v0=edges[i].from;
        int v1=edges[i].to;
        Weight c=edges[i].c;
        slash[v0][v1]=true;
        slash[v1][v0]=true;
        vector<int> v0s;
        vector<int> v1s;
        dfs(v0,-1,v0s);
        dfs(v1,-1,v1s);
        for(int j=0;j<v0s.size();j++){
            for(int k=0;k<v1s.size();k++){
                sc[v0s[j]][v1s[k]]=c;
                sc[v1s[k]][v0s[j]]=c;
            }
        }
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int s,t;
        cin>>s>>t;
        s--,t--;
        cout<<sum-sc[s][t]<<endl;
    }
    return 0;
}