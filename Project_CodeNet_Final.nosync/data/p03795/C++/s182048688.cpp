#include <bits/stdc++.h>
#define rep(var,cnt) for(int (var)=0; (var)<(int)(cnt); ++(var))
#define REP(var,init,cnt) for(int (var)=(init); (var)<(cnt); ++(var))
#define ran(var,vec) for(auto &(var):(vec))
#define all(v) (v).begin(),(v).end()
#define TF(flag) (flag)?1:0
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using ti = tuple<int,int,int>;
using tl = tuple<ll,ll,ll>;

template<typename T>
using vec = vector<T>;
template<typename T>
using mat = vector<vec<T>>;
template<typename T>
using cub = vector<mat<T>>;
template<typename T>
using val = valarray<T>;

template<typename T>
using pq = priority_queue<T>;
template<typename T>
using rpq = priority_queue<T,vec<T>,greater<T>>;

template<typename T1,typename T2>
ostream &operator<<(ostream &os, const pair<T1,T2> &p){
  os<<"P("<<p.first<<", "<<p.second<<") ";
  return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is, pair<T1,T2> &p){
  is>>p.first>>p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  cout<<"V{";
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<(i+1!=v.size()?" ":"");
  }
  cout<<"}";
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v){
  for(T &in:v) is>>in;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const valarray<T> &v){
  cout<<"V{";
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<(i+1!=v.size()?" ":"");
  }
  cout<<"}";
  return os;
}

template<typename T>
istream &operator>>(istream &is, valarray<T> &v){
  for(T &in:v) is>>in;
  return is;
}

// Usual Template End ================================================

// Template End ======================================================

int main(void){
  int N; cin>>N;
  cout<<N*800-N/15*200;
}












