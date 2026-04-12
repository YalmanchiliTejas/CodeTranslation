#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
typedef pair<int64_t,int64_t> P;
typedef pair<int64_t,P> T;
vector<P> G[4001];
int64_t ans[4001][4001]={};
class uft {//union-find tree
public:
    int parent[4010];
    int size[4010];
    int root(int x);
    bool same(int x,int y);
    void unite(int x,int y);
};
int uft::root(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = root(parent[x]);
}
bool uft::same(int x,int y){
    if(root(x)==root(y)){
        return true;
    }else{
        return false;
    }
}
void uft::unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x == y) return;
    parent[x] = y;
    size[y] = size[y]+size[x];
}
int64_t Kruskal(priority_queue<T, vector<T>, greater<T> > q,int N){
    uft u;
    for(int i=0;i<N;i++){
        u.parent[i]=i;
        u.size[i]=1;
    }
    int64_t ret=0;
    while(u.size[u.root(0)] != N && !q.empty()){
        T edge = q.top(); q.pop();
        int s=(edge.second).first;
        int t=(edge.second).second;
        if(u.root(s) != u.root(t) ){
            u.unite(s,t);
            ret += edge.first;
            G[s].push_back(P(t,edge.first));
            G[t].push_back(P(s,edge.first));
            //cout<<s<<' '<<t<<' '<<edge.first<<endl;
        }
    }
    return ret;
}

int main(){
    int N,M;
    cin>>N>>M;
    priority_queue<T, vector<T>, greater<T> > q;
    for(int i=0;i<M;i++){
        int a,b;
        int64_t c;
        cin>>a>>b>>c;
        a--; b--;
        T d = T(c,P(a,b));
        q.push(d);
    }
    int64_t an=Kruskal(q,N);
    //cout<<an<<endl;
    for(int i=0;i<N;i++){
        bool used[4010]={};
        used[i]=true;
        queue<P> qu;
        qu.push(P(i,0));
        while (!qu.empty()) {
            P v  = qu.front(); qu.pop();
            //cout<< v.first <<' '<< v.second <<endl;
            for(int j=0;j<G[v.first].size();j++){
                P u = G[v.first][j];
                if(!used[u.first]){
                    //cout<<v.first<<' '<<v.second<<' '<<u.first<<' '<<u.second<<endl;
                    used[u.first]=true;
                    ans[i][u.first]=max(v.second,u.second);
                    //cout<<"ans "<<i<<' '<<u.first<<' '<<ans[i][u.first]<<endl;cout<<endl;
                    qu.push(P(u.first,ans[i][u.first]));
                }
            }
        }
    }/*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<' ';
        }cout<<endl;
    }*/
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int s,t;
        cin>>s>>t;
        s--;t--;
        cout<< an - ans[s][t] << endl;
    }
    
    
    return 0;
}
