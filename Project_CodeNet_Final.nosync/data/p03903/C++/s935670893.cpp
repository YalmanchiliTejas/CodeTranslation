#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct cww{cww(){
    ios::sync_with_stdio(false);cin.tie(0);
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

namespace _DSU{
    int cnt=0;
    int mem[2][212345];
    int* get(){
        return mem[cnt++];
    }
}
LL res[112345];
int S[112345];
int T[112345];
set<int> query[41234];
int task[112345];
class UnionFind{
private:
    int *par,*rank;
    int find(int x){
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
public:
    UnionFind(int n,int *par,int *rank) :par(par),rank(rank){
        for(int i = 0; i < n; i++)par[i] = i,rank[i] = 0;
    }
    UnionFind(int n):UnionFind(n,_DSU::get(),_DSU::get()){}
    int unite(int x, int y){
        x = find(x);y = find(y);
        if (x == y)return -1;
        int sz=0;
        if(query[x].size()>query[y].size())swap(x,y);
        for(auto &it:query[x]){
            if(query[y].count(it)){
                task[sz++]=it;
                query[y].erase(it);
            }
            else query[y].insert(it);
        }
        query[x].clear();
        if (rank[x] < rank[y])swap(x,y);
        if(query[x].size()==0)swap(query[x],query[y]);
        par[y] = x;
        if (rank[x] == rank[y])rank[x]++;
        return sz;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};
typedef tuple<LL,int,int> E;
int main(){
    int N,M,Q;
    cin>>N>>M;
    vector<E> e(M);
    REP(i,M){
        int s,t;LL c;
        cin>>s>>t>>c;
        e[i]=E(c,s,t);
    }
    sort(e.begin(),e.end());
    
    cin>>Q;
    REP(i,Q){
        cin>>S[i]>>T[i];
        query[S[i]].insert(i);
        query[T[i]].insert(i);
    }
    LL cost=0;
    UnionFind uf(N+1);
    REP(i,M){
        int a,b;LL c;
        tie(c,a,b)=(e[i]);
        int k=uf.unite(a,b);
        if(k==-1)continue;
        REP(i,k){
            res[task[i]]=c;
        }
        cost+=c;
    }
    REP(i,Q)cout<<cost-res[i]<<fin;
    
    return 0;
}
