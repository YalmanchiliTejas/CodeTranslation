#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD=(LL)1e9+7;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

#define INF 1LL << 50

const LL MAX_V=100003;
int V,E;

int par[MAX_V];
int rnk[MAX_V];

void init(int n){
    REP(i,n){
        par[i]=i;
        rnk[i]=0;
    }
}

int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rnk[x]<rnk[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rnk[x]==rnk[y])rnk[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}

struct UnionFind {
    vector<int> par;
    int n, cnt;
    UnionFind(const int& x = 0) {init(x);}
    void init(const int& x) {par.assign(cnt=n=x, -1);}
    inline int find(const int& x) {return par[x] < 0 ? x : par[x] = find(par[x]);}
    inline bool same(const int& x, const int& y) {return find(x) == find(y);}
    inline bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const {return cnt;}
    inline int count(int x) {return -par[find(x)];}
};


struct edge{
    int u,v;
    LL cost;
};

edge es[2*MAX_V+3];

bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
LL kruskal(){
    sort(es,es+E,comp);
    init(V);
    LL res=0;
    REP(i,E){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main(){
    int N;
    cin>>N;V=N;
    vector<PLL>px,py;
    REP(i,N){
        LL x,y;
        cin>>x>>y;
        px.PB(MP(x,i));
        py.PB(MP(y,i));
    }
    SORT(px);SORT(py);
    edge e;
    E=0;
    REP(i,N-1){
        edge e;
        e.u=px[i].second;e.v=px[i+1].second;e.cost=px[i+1].first-px[i].first;
        es[E]=e;E++;
        e.u=py[i].second;e.v=py[i+1].second;e.cost=py[i+1].first-py[i].first;
        es[E]=e;E++;
    }
    
    cout<<kruskal()<<endl;
    return 0;
}