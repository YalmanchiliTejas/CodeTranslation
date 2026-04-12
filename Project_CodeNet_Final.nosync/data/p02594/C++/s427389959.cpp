#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using ld = long double;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using bl = bool;
using vbl = std::vector<bl>;
using vvbl = std::vector<vbl>;
using vvvbl = std::vector<vvbl>;
using ss = string;
using vss = std::vector<ss>;

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define repm(i,n,m) for(ll (i)=m;(i)<(ll)(n);(i)++)
#define repi(i,n) for(ll (i)=(n-1);(i)>=(ll)(0);(i)--)
#define repit(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
 
#define all(v) v.begin(), v.end()
#define println(v) {ll i=0; for(auto (a): v ){   cerr <<setw(2) <<i << " : "<<  a << endl; i++;}}
template<class T> 
void printsp(vector<T> v, size_t w=3){
  for(auto (a): v ) {cerr <<setw(w)<< a << " ";} cerr << endl;
} 
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> void bye(T a){cout << a << '\n'; exit(0);} 
template<class T1,class T2> void bye(T1 a,T2 b){cout << a <<" " << b << '\n'; exit(0);} 
template<class T1,class T2,class T3> void bye(T1 a,T2 b,T3 c){cout << a <<" " << b <<" " << c << '\n'; exit(0);} 
template<class T> void bye(vector<T> A)
{  
  rep(i,(ll)A.size()){
    cout << A[i];
    if(i!=(ll)A.size()-1){
      cout << " ";
    }
  }
  cout << endl;
  exit(0);
} 
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector<string>
ostream &operator<<(ostream &os, const vector<string> &vec) {
  
  ll N = to_string((ll)vec.size()).length();
  string head;
  rep(i,N+2){ head += "-";}
  rep(i,40){ head += to_string(i%10);}
  os << setw(N) << head << endl;
   
  for (ll i = 0; i < (ll)vec.size(); i++) {
    os << setw(N) << i << ": " << vec[i] << endl;
  } 
  return os;
}
// vector<ll>
ostream &operator<<(ostream &os, const vector<ll> &vec) {
  ll N = to_string((ll)vec.size()).length();
  for (ll i = 0; i < (ll)vec.size(); i++) {
    os << setw(N) << i << ": " <<vec[i] << endl;
  } 
  return os;
}
// vector<ld>
ostream &operator<<(ostream &os, const vector<ld> &vec) {
  ll N = to_string((ll)vec.size()).length();
  for (ll i = 0; i < (ll)vec.size(); i++) {
    os << setw(N) << i << ": " <<vec[i] << endl;
    //os <<vec[i] << endl;
  } 
  return os;
}
// vvll
ostream &operator<<(ostream &os, const vector<vector<ll>> &mat) {
  ll keta = 1;
  rep(i,mat.size()){
    rep(j,mat[i].size()){
      ll x = mat[i][j];
      chmax(keta,(ll)to_string(x).length());
    }
  }
  ll N = to_string((ll)mat.size()).length();
  rep(i,mat.size()){
    os << setw(N) << i << ": " ;
    rep(j,mat[i].size()){
      ll x = mat[i][j];
      os << setw(keta+1) <<x;
    }
    os << endl;
  }  
  return os;
}

// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {

  for (ll i = 0; i < (ll)vec.size(); i++) {
    //os << setw(3) <<i <<" : "<< setw(5) << vec[i] << endl;
    os << setw(5) << vec[i];
  } 
  os << endl;
  return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repit(itr ,  map_var){
    //for(auto itr :  map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repit(itr ,  set_var){
      //for( auto itr : set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    
  return os;
}
#define DUMPOUT cerr
#define DUMPCOLOR ("\033[36m")
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << DUMPCOLOR;
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
    DUMPOUT << "\033[m";
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << DUMPCOLOR                                                      \
            << "" << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "\033[m"                                                        \
            << "",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct Fast{
  Fast(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
  }
} fast;

inline vll cinvll(ll N, ll minus = 0){
  vll A(N);
  rep(i,N){
    cin >> A[i];
    A[i] -= minus;
  }
  return move(A);
}
inline vvll zerosll(ll H, ll W, ll val=0){
  vvll A(H,vll(W,val));
  return move(A);
}
inline vvvll zerosll3(ll H, ll W,ll C, ll val=0){
  vvvll A(H,vvll(W,vll(C,val)));
  return move(A);
}

vvll cinvll2(ll H,ll W,ll bias = 0){
  vvll A = zerosll(H,W);
  rep(i,H){
    rep(j,W){
      cin >> A[i][j];
      A[i][j] += bias;
    }
  }
  return move(A);
}    
tuple<vll,vll> aho2(ll N){
  vll A(N),B(N);
  rep(i,N){
    cin >> A[i] >> B[i];
  }
  return(make_tuple(A,B));
}

template<class T=ll> inline vector<T> cinv(ll N,T val=0){ vector<T> v(N); rep(i, N){cin>>v[i]; v[i]+=val;} return move(v);}
template<class T=ll> inline vector<vector<T>> zeros(ll H, ll W, T val=0){
  vector<vector<T>> A(H,vector<T>(W,val));
  return move(A);
}
template<class T=ll> inline vector<vector<vector<T>>> zeros3(ll H, ll W,ll C, T val=0){
  vector<vector<vector<T>>> A(H,vector<vector<T>>(W,vector<T>(C,val)));
  return move(A);
}


template<typename TTT>
vector<ll> arg_sort(const vector<TTT> &A, bool ascend = true) {
  vector<ll> index(A.size());
  iota(index.begin(), index.end(), 0);
  if (ascend) {
    std::sort(all(index), [&A](TTT i1, TTT i2) {
      return A[i1] < A[i2];
      });
  }
  else {
    std::sort(all(index), [&A](TTT i1, TTT i2) {
      return A[i1] > A[i2];
      });
  }
  return index;
}
template<typename TTT>
vector<TTT> permute(vector<TTT> src, vll idx){
  vector<TTT> dst(src.size());
  rep(i,src.size()){
    dst[i] = src[idx[i]];
  }
  return move(dst);
}


void func()
{
  ll N;
  cin >> N;
  if(N>=30){
    bye("Yes");
  }
  bye("No");

}


int main()
{
  dump("start");
  func();
  return 0;
}





