#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC push_options
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define EPS (1e-10)
#define endl ('\n')
#define MOD 1000000007LL
//#define MOD 998244353LL
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
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
inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}
inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}
// inline cint cgcd(cint A,cint B){return B?cgcd(B,A%B):A;}
// inline cint clcm(cint A,cint B){return A/cgcd(A,B)*B;}
bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
auto call=[](auto f,auto... args){return f(f,args...);};

int main(){
    lint n;
    cin>>n;
    vec a(n);
    rep(i,n)cin>>a[i];
    vector<map<lint,lint>>dp(n+1);
    dp[0][0]=0;
    rep(i,n){
        for(auto d:dp[i]){
            if(abs(i/2-d.first)<=20)dp[i+1][d.first]=d.second;
        }
        if(i){
            for(auto d:dp[i-1]){
                if(abs(i/2-d.first)<=20){
                    if(!dp[i+1].count(d.first+1))dp[i+1][d.first+1]=-INF;
                    chmax(dp[i+1][d.first+1],d.second+a[i]);
                }
            }
        }else{
            if(!dp[i+1].count(1))dp[i+1][1]=-INF;
            chmax(dp[i+1][1],a[0]);
        }
    }
    cout<<dp[n][n/2]<<endl;
}