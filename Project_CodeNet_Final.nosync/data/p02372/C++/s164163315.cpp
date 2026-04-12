#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define INF 10000000
#define _for(j,N) for(int i = (j); i < (N);++i)

struct Edge{
    int w;
    int to;
    Edge(int wi,int toi):w(wi),to(toi){;}
};

struct Compare{
    inline bool operator()(const Edge& e1,const Edge& e2){
        return e1.w < e2.w;
    }
};

int n;

typedef vector<int> Vec;
typedef pair<int,int> Pii;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Vec pre;
Graph G;

Vec dijkstra(int v){

    Vec ret_val(n,INF);
    ret_val[v] = 0;
    priority_queue<Edge,Edges,Compare> pq;
    pq.push(Edge(0,v));

    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        int to = e.to;
        int w = e.w;

        if(ret_val[to] < w) continue;

        for(auto a = G[to].begin();a != G[to].end();++a){
            if(w + a->w < ret_val[a->to]){
                ret_val[a->to] = w + a->w;
                pq.push(Edge(w + a->w,a->to));
            }
        }
    }

    return ret_val;
}

int find_father(int v){
    Vec di = dijkstra(v);
    int mv = 0;
    int weight = 0;
    _for(0,n){
        if(weight < di[i]){
            weight = di[i];
            mv = i;
        }
    }
    return mv;
}



int main()
{
    int s,t,w;
    scanf("%d",&n);
    G.resize(n);
    pre.resize(n);

    _for(0,n-1){
        scanf("%d %d %d",&s,&t,&w);
        G[s].push_back(Edge(w,t));
        G[t].push_back(Edge(w,s));
    }

    int v1 = find_father(0);
    int v2 = find_father(v1);

    Vec di1 = dijkstra(v1);
    Vec di2 = dijkstra(v2);

    _for(0,n){
        printf("%d\n",max(di1[i],di2[i]));
    }

    return 0;
}
