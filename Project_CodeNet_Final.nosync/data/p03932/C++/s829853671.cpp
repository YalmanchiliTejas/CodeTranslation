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

using namespace std;

using ll=long long int;
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
  Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

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
  edge(int to, T cost) : to(to), cost(cost) {}
};
template<typename T>
using edges=vector<edge<T>>;
template<typename T>
using WeightGraph=vector<edges<T>>;

using Graph=vector<vector<int>>;



template<typename T> using vc=vector<T>;
template<typename T> using vvc=vector<vector<T>>;
template<typename T> using vvvc=vector<vector<vector<T>>>;
template<typename T> using vvvvc=vector<vvvc<T>>;
template<typename T> using vvvvvc=vector<vvvvc<T>>;

template<class T,class U>inline constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>inline constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}
#define bit(n,k) ( (n>>k)&1 )

inline void bin101(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout<<fixed<<setprecision(20);
}

template<typename T>
inline void Yes(T flag){
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

template<typename T>
inline void YES(T flag){
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

//1-indexed vector cin
template<typename T>
inline void vin1(vector<T> &v){
    for(int i=1;i<v.size();i++) cin>>v[i];
}

//0-indexed vector cin
template<typename T>
inline void vin0(vector<T> &v){
    for(int i=0;i<v.size();i++) cin>>v[i];
}

//1-indexed vector<vector> cin
template<typename T>
inline void vin1(vector<vector<T>> &v){
    for(int i=1;i<v.size();i++){
        for(int j=1;j<v[i].size();j++) cin>>v[i][j];
    }
}

//0-indexed vector<vector> cin
template<typename T>
inline void vin0(vector<vector<T>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++) cin>>v[i][j];
    }
}



//デバッグ
template<typename T>
inline void vout(const vector<T> &v){
    cout<<"\nstart\n";
    const int sz=v.size();
    for(int i=0;i<sz;i++){
        cout<<i<<" "<<v[i]<<'\n';
    }
    cout<<"end\n"<<endl;
}
//デバッグ
template<typename T>
inline void vout(const vvc<T> &v){
    cout<<"\nstart\n";
    const int sz=v.size();
    for(int i=0;i<sz;i++){
        int ssz=v[i].size();
        for(int j=0;j<ssz;j++){
            cout<<i<<" "<<j<<" "<<v[i][j]<<'\n';
        }
    }
    cout<<"\nend\n"<<endl;
}

//デバッグ(グリッド)
template<typename T>
inline void gvout(const vector<T> &v){
    cout<<"\nstart\n";
    const int sz=v.size();
    for(int i=0;i<sz;i++){
        if(i) cout<<" ";
		cout<<v[i];
    }
    cout<<"\nend\n"<<endl;
}
//デバッグ(グリッド)
template<typename T>
inline void gvout(const vvc<T> &v){
    cout<<"\nstart\n";
    const int sz=v.size();
    for(int i=0;i<sz;i++){
        int ssz=v[i].size();
        for(int j=0;j<ssz;j++){
			if(j) cout<<" ";
            cout<<v[i][j];
        }
		cout<<endl;
    }
    cout<<"end\n"<<endl;
}


//デバッグ
template<typename T>
inline void vout(const vvvc<T> &v){
    cout<<"\nstart\n";
    const int sz=v.size();
    for(int i=0;i<sz;i++){
        int ssz=v[i].size();
        for(int j=0;j<ssz;j++){
            int sssz=v[i][j].size();
            for(int k=0;k<sssz;k++){
                cout<<i<<" "<<j<<" "<<k<<" "<<v[i][j][k]<<'\n';
            }
        }
    }
    cout<<"end\n"<<endl;
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

//要素数a 初期値x
template<typename T>
inline vector<T> vmake(int a,T x){
  return vector<T>(a,x);
}

//data[a][b] 初期値x
template<typename T>
inline vector<vector<T>> vmake(int a,int b,T x){
  return vector<vector<T>>(a, vector<T>(b,x));
}

//data[a][b][c] 初期値x
template<typename T>
inline vector<vector<vector<T>>> vmake(int a,int b,int c,T x){
  return vector<vector<vector<T>>> (a, vector<vector<T>>(b, vector<T>(c, x)));
}

//data[a][b][c][d]　初期値x
template<typename T>
inline vector<vector<vector<vector<T>>>> vmake(int a,int b,int c,int d,T x){
  return vector<vector<vector<vector<T>>>> (a,vvvc<T>(b,vvc<T>(c,vc<T>(d,x))));
}

//data[a][b][c][d][e] 初期値x
template<typename T>
inline vvvvvc<T> vmake(int a,int b,int c,int d,int e,T x){
  return vvvvvc<T> (a,vvvvc<T>(b,vvvc<T>(c,vvc<T>(d,vc<T>(e,x)))));
}

//1ビットの数を返す
inline int popcount(int x){
  return __builtin_popcount(x);
}
//1ビットの数を返す
inline int popcount(ll x){
  return __builtin_popcountll(x);
}

//queのfront() pop()
template<typename T>
inline T pop(queue<T> &que){
    assert(!que.empty());
    T x=que.front();
    que.pop();
    return x;
}

//priority_que top() pop()
template<typename T>
inline T pop(priority_queue<T> &que){
  assert(!que.empty());
  T x=que.top();
  que.pop();
  return x;
}

//stack top() pop()
template<typename T>
inline T pop(stack<T> &st){
  assert(!st.empty());
  T x=st.top();
  st.pop();
  return x;
}

#define SZ(x) ( (int)x.size()  )
#define pb push_back
#define eb emplace_back

/*
満たすものの個数を返す
mode:0 x未満
mode:1 x以下の数
mode:2 x以上の数
mode:3 x超
mode:4 x
*/
template<typename T>
inline int count_bound(vector<T> &v,T x,int mode){
    switch(mode){
        case 0:
            return lower_bound(v.begin(),v.end(),x)-v.begin();
        case 1:
            return upper_bound(v.begin(),v.end(),x)-v.begin();
        case 2:
            return v.end()-lower_bound(v.begin(),v.end(),x);
        case 3:
            return v.end()-upper_bound(v.begin(),v.end(),x);
        case 4:
            return upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x);
    }
}

/*
mode:0 xより小さい数で最大の数
mode:1 x以下の数で最大の数
mode:2 x以上の数で最小の数
mode:3 xより大きい数で最小の数
*/
template<typename T>
inline T value_bound(vector<T> &v,T x,int mode){
    switch(mode){
        case 0:
            return *(--lower_bound(v.begin(),v.end(),x));
        case 1:
            return *(--upper_bound(v.begin(),v.end(),x));
        case 2:
            return *lower_bound(v.begin(),v.end(),x);
        case 3:
            return *upper_bound(v.begin(),v.end(),x);
    }
}



constexpr int MAX=1<<30;
constexpr ll INF=1LL<<62;
constexpr ll MOD=1e9+7;
constexpr int dx[]={1,0},dy[]={0,1};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main(){
	bin101();

    int H,W;
    cin>>H>>W;
    auto a=vmake(H,W,0);
    vin0(a);
    //gvout(a);

    auto dp=vmake(H+W-1,H,H,-1);
    dp[0][0][0]=a[0][0];

    for(int i=0;i<H+W-1;i++){

        for(int s=0;s<H;s++){
            for(int e=0;e<H;e++){
                if(dp[i][s][e]==-1) continue;
                int sh=s,eh=e;
                int sw=i-sh,ew=i-eh;
                for(int k=0;k<2;k++){
                    for(int l=0;l<2;l++){
                        int snh=sh+dx[k],snw=sw+dy[k];
                        int enh=eh+dx[l],enw=ew+dy[l];
                        if(snh>=H || snw>=W || enh>=H || enw>=W) continue;
                        int x;
                        if(snh==enh) x=a[snh][snw];
                        else x=a[snh][snw]+a[enh][enw];
                        chmax(dp[i+1][snh][enh],dp[i][sh][eh]+x);
                    }
                }
            }
        }
    }
    //vout(dp);
    cout<<dp[H+W-2][H-1][H-1]<<endl;
}
