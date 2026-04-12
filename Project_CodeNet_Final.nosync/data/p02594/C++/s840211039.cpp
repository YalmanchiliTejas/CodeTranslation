/*
vectorの配列を吐き出す関数はvfillと同じ要領で簡潔に書けそう
だけど面倒
vfillの範囲指定をできるようにしたい
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx")  //Enable AVX
#pragma GCC optimize("Ofast")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <iomanip>
#include <functional>
#include <complex>
#include <iostream>
#include <future>
#include <thread>

using namespace std;

using ll=int_fast64_t;
using u64=uint_fast64_t;

using pii=pair<int,int>;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using psi=pair<string,int>;
using pis=pair<int,string>;
using psl=pair<string,ll>;
using pls=pair<ll,string>;
using pss=pair<string,string>;

//辺 fromあり
template<typename T >
struct Edge {
  int from, to;
  T cost;

  Edge()=default;
  Edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}

  inline bool operator<(const Edge p)const noexcept{
    return cost<p.cost;
  }

  inline bool operator>(const Edge p)const noexcept{
    return cost>p.cost;
  }

};

//辺 fromがない
template<typename T >
struct edge {
  int to;
  T cost;
  edge()=default;
  edge(int _to, T _cost) : to(_to), cost(_cost) {}
};

template<typename T>
using edges=vector<edge<T>>;
template<typename T>
using WeightGraph=vector<edges<T>>;

using Graph=vector<vector<int>>;

template<class T,class U>inline constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>inline constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}
#define bit(n,k) ( ( (n)>>(k) )&1 )

inline void bin101(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout<<fixed<<setprecision(20);
}

//1-indexed vector cin
template<typename T>
inline void vin1(vector<T> &v){
    for(size_t i=1;i<v.size();i++) cin>>v[i];
}

//0-indexed vector cin
template<typename T>
inline void vin0(vector<T> &v){
    for(size_t i=0;i<v.size();i++) cin>>v[i];
}

//1-indexed vector<vector> cin
template<typename T>
inline void vin1(vector<vector<T>> &v){
    for(size_t i=1;i<v.size();i++){
        for(size_t j=1;j<v[i].size();j++) cin>>v[i][j];
    }
}

//0-indexed vector<vector> cin
template<typename T>
inline void vin0(vector<vector<T>> &v){
    for(size_t i=0;i<v.size();i++){
        for(size_t j=0;j<v[i].size();j++) cin>>v[i][j];
    }
}


bool DEBUG_MODE=false;

#define debug(a) if(DEBUG_MODE){cout<<#a;PRINT(a);cout<<flush;}
#define debug2(a,b) if(DEBUG_MODE){debug(a);debug(b);}
#define debug3(a,b,c) if(DEBUG_MODE){debug(a);debug(b);debug(c);}
#define debug4(a,b,c,d) if(DEBUG_MODE){debug(a);debug(b);debug(c);debug(d);}
#define debug5(a,b,c,d,e) if(DEBUG_MODE){debug(a);debug(b);debug(c);debug(d);debug(e);}

#define gdebug(x) if(DEBUG_MODE){cout<<#x;GPRINT(x);} 

template<class T>void PRINT(const T x){cout<<":"<<x<<"\n";}

//デバッグ
template<typename T>
void PRINT(const vector<T> &v,int a=-1){
    if(!DEBUG_MODE) return;
    cout<<":1d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        cout<<i<<":"<<v[i]<<'\n';
    }
    cout<<"\n";
}

//デバッグ
template<typename T>
void PRINT(const vector<vector<T>> &v,int a=-1,int b=-1){
    if(!DEBUG_MODE) return;
    cout<<":2d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        for(size_t j=0;j<v[i].size() and (b<0 or j<=(size_t)b);j++){
            cout<<i<<"-"<<j<<":"<<v[i][j]<<"\n";
        }
    }
    cout<<"\n";
}

//デバッグ
template<typename T>
void PRINT(const vector<vector<vector<T>>> &v,int a=-1,int b=-1,int c=-1){
    if(!DEBUG_MODE) return;
    cout<<":3d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        for(size_t j=0;j<v[i].size() and (b<0 or j<=(size_t)b);j++){
            for(size_t k=0;k<v[i][j].size() and (c<0 or k<=(size_t)c);k++){
                cout<<i<<"-"<<j<<"-"<<k<<":"<<v[i][j][k]<<"\n";
            }
        }
    }
    cout<<"\n";
}

//デバッグ
template<typename T>
void PRINT(const vector<vector<vector<vector<T>>>> &v,int a=-1,int b=-1,int c=-1,int d=-1){
    if(!DEBUG_MODE) return;
    cout<<":4d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        for(size_t j=0;j<v[i].size() and (b<0 or j<=(size_t)b);j++){
            for(size_t k=0;k<v[i][j].size() and (c<0 or k<=(size_t)c);k++){
                for(size_t l=0;l<v[i][j][k].size() and (d<0 or l<=(size_t)d);l++){
                    cout<<i<<"-"<<j<<"-"<<k<<"-"<<l<<":"<<v[i][j][k][l]<<"\n";
                }
            }
        }
    }
    cout<<"\n";
}

//デバッグ
template<typename T>
void PRINT(const vector<vector<vector<vector<vector<T>>>>> &v,int a=-1,int b=-1,int c=-1,int d=-1,int e=-1){
    if(!DEBUG_MODE) return;
    cout<<":5d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        for(size_t j=0;j<v[i].size() and (b<0 or j<=(size_t)b);j++){
            for(size_t k=0;k<v[i][j].size() and (c<0 or k<=(size_t)c);k++){
                for(size_t l=0;l<v[i][j][k].size() and (d<0 or l<=(size_t)d);l++){
                    for(size_t m=0;m<v[i][j][k][l].size() and (e<0 or m<=(size_t)e);m++){
                        cout<<i<<"-"<<j<<"-"<<k<<"-"<<l<<"-"<<m<<":"<<v[i][j][k][l][m]<<"\n";
                    }
                }
            }
        }
    }
    cout<<"\n";
}

template<typename T>
void PRINT(const set<T> &S){
    if(!DEBUG_MODE) return;
    int now=0;
    for(auto x:S){
        cout<<now++<<":"<<x<<"\n";
    }
}

template<typename T,typename U>
void PRINT(const map<T,U> &M){
    if(!DEBUG_MODE) return;
    cout<<":map\n";
    size_t now=0;
    for(auto &x:M){
        cout<<now++<<":"<<x<<"\n";
    }
}


//デバッグ(グリッド)
template<typename T>
void GPRINT(const vector<T> &v,int a=-1){
    if(!DEBUG_MODE) return;
    cout<<":1d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        if(i) cout<<",";
		cout<<v[i];
    }
}

//デバッグ(グリッド)
template<typename T>
void GPRINT(const vector<vector<T>> &v,int a=-1,int b=-1){
    if(!DEBUG_MODE) return;
    cout<<":2d\n";
    for(size_t i=0;i<v.size() and (a<0 or i<=(size_t)a);i++){
        for(size_t j=0;j<v[i].size() and (b<0 or j<=(size_t)b);j++){
            if(j) cout<<",";
            cout<<v[i][j];
        }
        cout<<"\n";
    }
}

//pair cout
template<typename T, typename U>
inline ostream &operator<<(ostream &os,const pair<T,U> &p) {
  os<<p.first<<" "<<p.second;
  return os;
}

//pair cin
template<typename T, typename U>
inline istream &operator>>(istream &is,pair<T,U> &p) {
  is>>p.first>>p.second;
  return is;
}

//ソート
template<typename T>
inline void vsort(vector<T> &v){
    sort(v.begin(),v.end());
}

//逆順ソート
template<typename T>
inline void rvsort(vector<T> &v){
  sort(v.rbegin(),v.rend());
}

//要素数n 初期値x
template<typename T>
inline vector<T> vmake(size_t n,T x){
  return vector<T>(n,x);
}

//a,b,c,x data[a][b][c] 初期値x
template<typename... Args>
auto vmake(size_t n,Args... args){
    auto v=vmake(args...);
    return vector<decltype(v)>(n,move(v));
}

template<typename T,typename... X>
inline void vfill(T &t,const X... x){
    t=T(x...);
}

template<typename T,typename... X>
void vfill(vector<T> &t,const X... x){
    for(auto &s:t) vfill(s,x...);
}

//最後に改行があるので注意
template<typename T>
void vout(const vector<T> &v,string s=" ",size_t f=0,int t=-1){
    for(size_t i=f;i<v.size() and(t<0 or i<=(size_t)t);i++){
        if(i!=f) cout<<s;
        cout<<v[i];
    }
    cout<<"\n";
}

//最後に改行があるので注意
template<typename T>
void vout(const vector<vector<T>> &v,string s=" ",int fh=0,int th=-1,int fw=0,int tw=-1){
    for(size_t i=fh;i<v.size() and (th<0 or i<=(size_t)th);i++){
        for(size_t j=fw;j<v[i].size() and (tw<0 or j<=(size_t)tw);j++){
            if(j!=fw) cout<<s;
            cout<<v[i][j];
        }
        cout<<"\n";
    }
}

//1ビットの数を返す
inline int popcount(int x){
  return __builtin_popcount(x);
}
//1ビットの数を返す
inline int popcount(ll x){
  return __builtin_popcountll(x);
}

constexpr int MAX=(1<<30)-1;
constexpr ll INF=(1LL<<62)-1;
constexpr ll MOD=1e9+7;
constexpr int dx[]={1,-1,0,0},dy[]={0,0,-1,1};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void solve(){
    int X;
    cin>>X;
    if(X>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    DEBUG_MODE=true;
    bin101();
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    int T=1;
    while(T--) solve();
}