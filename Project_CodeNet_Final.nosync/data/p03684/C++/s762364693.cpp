#include<bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<LL,LL>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    LL from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};
class UnionFind{
private:
    vector<int> vec;
public:
    void init(int N){
        vec.resize(N);
        for(int a = 0;a < N;a++)
        {
            vec[a]=-1;
        }
    }
    int root(int a)
    {
        if(vec[a] < 0)return a;
        else return vec[a] = root(vec[a]);
    }
    bool connect(int a,int b)
    {
        a = root(a);
        b = root(b);
        if(a==b)return false;
        if(vec[a] > vec[b])swap(a,b);
        vec[a] += vec[b];
        vec[b] = a;
        return true;
    }
    bool check(int a,int b){
        a = root(a);
        b = root(b);
        if(a==b)return true;
        else return false;
    }
};
bool comp(const Edge& e1, const Edge& e2){
    return e1.value < e2.value;
}
LL kruskal(V<Edge> Edges,int N){
    sort(ALL(Edges), comp);
    UnionFind Uni;
    Uni.init(N);
    LL ans = 0;
    for(int a = 0;a < Edges.size();a++){
        Edge e = Edges.at(a);
        if(!Uni.check(e.from,e.to)){
            Uni.connect(e.from,e.to);
            ans += e.value;
        }
    }
    return ans;
}
int main(){
    CIN(N);
    V<Edge> vec;
    V<pair<LL,LL>> q;
    V<pair<LL,LL>> p;
    REP(a,N){
        LCIN(b);
        LCIN(c);
        q.pb(make_pair(b,a));
        p.pb(make_pair(c,a));
    }
    sort(ALL(p));
    sort(ALL(q));
    for(int a = 0;a < N-1;a++){
        Edge e(p.at(a).second,p.at(a+1).second,abs(p.at(a).first-p.at(a+1).first));
        Edge w(q.at(a).second,q.at(a+1).second,abs(q.at(a).first-q.at(a+1).first));
        vec.pb(e);
        vec.pb(w);
    }
    COUT(kruskal(vec,N));
    return 0;
}
