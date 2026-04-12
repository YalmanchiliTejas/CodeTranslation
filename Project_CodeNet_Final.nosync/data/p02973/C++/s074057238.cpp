#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
#define cinv(n,v) VL v(n);rep(i,n)cin>>v[i]
#define itn int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(all(a),greater<>())
#define SZ(a) (signed)(a.size())
#define debg(a) cout<<#a<<" "<<a<<endl;
#define call(a) for(auto i:a)cout<<i<<" ";cout<<endl
#define callp(a) for(auto [k,v]:a)cout<<k<<":"<<v<<endl
#define show(a) for(cont &y:a){for(cont &x:y){cout<<x<<" ";}cout<<endl;}
#define out(a) cout<<(a)<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define LINE puts("------------------")
#define fi first
#define se second
#define V vector
#define P pair
#define T tuple
#define PQ priority_queue
#define cont const auto
#define VV(type,name,y,x,a) vector<vector<type>> name = vector<vector<type>>(y,vector<type>(x,a))
typedef long long ll;
typedef double D;
typedef string str;
typedef vector<ll> VL;
typedef pair<ll,ll> PL;
typedef vector<pair<ll,ll>> VP;
typedef tuple<ll,ll,ll> T3;
typedef tuple<ll,ll,ll,ll> T4;
typedef struct{ll to;ll cost;} Graphs;
typedef V<V<Graphs>> AdjList;
const signed INF = (1LL<<30);
const long long MOD = (1e9+7);
const long long LINF = (1LL<<60);
const long long LMAX = LLONG_MAX;
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<class T>T center(T a,T b,T c){
  if( (a<=b&&b<=c)||(a>=b&&b>=c) )return b;
  if( (b>=a&&a>=c)||(b<=a&&a<=c) )return a;
  return c;
}
void print(){cout<<endl;}
template<class Head,class... Tail>
void print(Head&& head, Tail&&... tail){
  cout<<head<<", ";
  print(forward<Tail>(tail)...);
}
void input(){}
template<class Head,class... Tail>
void input(Head&& head, Tail&&... tail){
  cin>>head;
  input(forward<Tail>(tail)...);
}
template<typename T>
ostream &operator<<(ostream&out,const vector<T>&v){
  if(!v.empty()){
    copy(v.begin(),v.end(),ostream_iterator<T>(out,", "));
    out<<"\b\b";
  }
  return out;
}
template<typename T1, typename T2>
ostream &operator<<(ostream&out,const pair<T1,T2>&p){
  out<<p.first<<", "<<p.second;
  return out;
}
template<typename T>
ostream &operator<<(ostream&out,const set<T>&st){
  for(const auto&elemnt:st)out<<elemnt<<", ";
  return out;
}
template<typename T1,typename T2>
ostream &operator<<(ostream&out,const vector<pair<T1,T2>>&vp){
  for(const auto &element:vp)
    out<<element.first<<", "<<element.second<<"\n";
  return out;
}
template<typename T>
istream &operator>>(istream&input,vector<T>&v){
  for(T&elemnt:v)input>>elemnt;
  return input;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  
  ll n;
  cin>>n;
  vector<ll> a(n);
  cin>>a;

  multiset<ll> st;
  st.insert(a[0]);
  for(int i=1;i<n;++i){
    if(a[i]<=(*st.begin())){
      st.insert(a[i]);
    }
    else{
      st.insert(a[i]);
      auto itr=st.find(a[i]);
      itr--;
      st.erase(itr);
    }
  }
  out(SZ(st));



  return 0;
}
