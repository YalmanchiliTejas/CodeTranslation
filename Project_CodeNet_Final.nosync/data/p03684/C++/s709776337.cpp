#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

struct Edge{
    int u,v,cost;
};
struct Node{
    int x,y,id;
};

bool compx(Node& x,Node& y){
    return x.x<y.x ;
}
bool compy(Node& x,Node& y){
    return x.y<y.y;
}
bool compc(Edge& x,Edge& y){
    return x.cost<y.cost;
}

int pare[100000];
int trank[100000];

int find(int u){
    if(u==pare[u]){
        return u;
    }else{
        return pare[u]=find(pare[u]);
    }
}

void unite(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v){
        return;
    }
    if(trank[u]<trank[v]){
        pare[u]=v;
    }else{
        pare[v]=u;
        if(trank[u]==trank[v]){
            trank[u]++;
        }
    }
    return;
}

int main() {
    int N;
    cin>>N;
    vector<Edge> edge;
    vector<Node> node;
    REP(i,N){
        int x,y;
        cin>>x>>y;
        Node node_;
        node_.x=x;
        node_.y=y;
        node_.id=i;
        node.push_back(node_);

        pare[i]=i;
        trank[i]=0;
    }
    sort(node.begin(),node.end(),compx);
    REP(i,N-1){
        Edge edge_;
        edge_.u=node[i].id;
        edge_.v=node[i+1].id;
        edge_.cost=node[i+1].x-node[i].x;
        edge.push_back(edge_);
    }
    sort(node.begin(),node.end(),compy);
    REP(i,N-1){
        Edge edge_;
        edge_.u=node[i].id;
        edge_.v=node[i+1].id;
        edge_.cost=node[i+1].y-node[i].y;
        edge.push_back(edge_);
    }
    sort(ALL(edge),compc);
    long long ans =0;
    REP(i,edge.size()){
        Edge e =edge[i];
        if(find(e.u)!=find(e.v)){
            ans+=e.cost;
            unite(e.u,e.v);
        }
    }
    cout<<ans<<endl;

    return 0;
}