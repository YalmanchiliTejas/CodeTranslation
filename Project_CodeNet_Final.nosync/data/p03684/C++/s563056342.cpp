#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
typedef vector<LL> V;
    namespace _DSU{
    int cnt=0;
    int mem[2][412345];
    int* get(){
        return mem[cnt++];
    }
}
class UF{
private:
    int *par,*rank;
    int find(int x){
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
    }
public:
    UF(int n,int *par,int *rank) :par(par),rank(rank){
	REP(i,n)par[i] = i,rank[i] = 0;
    }
    UF(int n):UF(n,_DSU::get(),_DSU::get()){}
    bool unite(int x, int y){
	x = find(x);y = find(y);
	if (x == y)return false;
	if (rank[x] < rank[y]) par[x] = y;
	else{
	    par[y] = x;
	    if (rank[x] == rank[y])rank[x]++;
	}
	return true;
    }
    bool same(int x, int y){
	return find(x) == find(y);
    }
};
LL X[112345];
LL Y[112345];
typedef pair<int,int> P;
typedef pair<LL,P> E;
int main(){
    int N;
    cin>>N;
    map<LL,vector<int>> x,y;
    REP(i,N){
        int a,b;
        cin>>a>>b;
        x[a].pb(i);
        y[b].pb(i);
    }
    int M=0;
    int K=0;
    for(auto &it:x)X[M++]=(it.fi);
    for(auto &it:y)Y[K++]=(it.fi);
    UF uf(N+M+K);

    M=0;
    for(auto &it:x){
        for(auto &j:it.se)uf.unite(N+M,j);
        M++;
    }
    K=0;
    for(auto &it:y){
        for(auto &j:it.se)uf.unite(N+M+K,j);
        K++;
    }

    
    vector<E> e;
    FOR(i,1,M)e.pb(E(X[i]-X[i-1],P(N+i-1,N+i)));
    FOR(i,1,K)e.pb(E(Y[i]-Y[i-1],P(N+M+i-1,N+M+i)));
    sort(ALL(e));
    LL res=0;
    for(auto &it:e){
        if(uf.unite(it.se.fi,it.se.se))
            res+=it.fi;
    }
    cout<<res<<endl;
    
    return 0;
}
