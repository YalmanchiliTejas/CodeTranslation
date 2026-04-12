#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC push_options
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#include <xmmintrin.h>
#include <immintrin.h>
using namespace::std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<0>> cdouble;
// typedef mp::cpp_int cint;
template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF (9223372036854775807LL)
#define EPS (1e-10)
#define endl ('\n')
#define MOD 1000000007LL
//#define MOD 998244353LL
//#define MOD 18446744069414584321ULL
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(lint i=0;i<t.size();i++)output(t[i]);}
#define rep(i,n) for(lint i=0;i<lint(n);++i)
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrep(i,n) for(lint i=lint(n)-1;i>=0;--i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
#define all(n) begin(n),end(n)
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
//inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}
//inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}
// inline cint cgcd(cint A,cint B){return B?cgcd(B,A%B):A;}
// inline cint clcm(cint A,cint B){return A/cgcd(A,B)*B;}
bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
auto call=[](auto f,auto... args){return f(f,args...);};
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}

vector<vector<pair<lint,lint>>>g;
vector<lint>diff;
void dfs(lint n){
    for(auto [e,c]:g[n]){
        if(chmin(diff[e],diff[n]+c))dfs(e);
    }
}

struct lca{
    using lint=long long;
    vector<vector<lint>>g;
    vector<int>sz,in,out,nxt,par;
    lca(vector<vector<lint>>g,int s):g(g),sz(g.size(),0),in(g.size(),0),out(g.size(),0),nxt(g.size(),s),par(g.size(),s){
        dfs_sz(s,-1);
        dfs_hld(s,-1);
    }
    void dfs_sz(int v,int p) {
        sz[v] = 1;
        for(auto &u: g[v]) {
            if(p==u)continue;
            dfs_sz(u,v);
            sz[v]+=sz[u];
            if(sz[u]>sz[g[v][0]])swap(u,g[v][0]);
        }
    }
    void dfs_hld(int v,int p) {
        static int t=0;
        in[v]=t++;
        for(auto u: g[v]){
            if(p==u)continue;
            nxt[u]=(u==g[v][0]?nxt[v]:u);
            par[u]=(u==g[v][0]?par[v]:v);
            dfs_hld(u,v);
        }
        out[v] = t;
    }
    int query(int s,int t){
        while(nxt[s]!=nxt[t]){
			if(sz[nxt[s]]>sz[nxt[t]])t=par[t];
			else s=par[s];
		}
        return sz[s]>sz[t]?s:t;
    }
    int distance(int s,int t){
		int res=0;
		while(nxt[s]!=nxt[t]){
			if(sz[nxt[s]]>sz[nxt[t]]){
				res+=in[t]-in[nxt[t]]+1;
				t=par[t];
			}
			else {
				res+=in[s]-in[nxt[s]]+1;
				s=par[s];
			}
		}
		return res+abs(in[s]-in[t]);
	}
};
int main(){
    lint n;
    cin>>n;
    vec a(n);
    rep(i,n)cin>>a[i];
    rep(i,n)a[i]*=-1;
    vec v;
    rep(i,n){
        auto itr=upper_bound(all(v),a[i]);
        if(itr==v.end())v.push_back(a[i]);
        else (*itr)=a[i];
    }
    cout<<v.size()<<endl;
}