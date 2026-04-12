/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,t) for (ll i = (ll)(0); i < (ll)(t); i++)
#define rep2(i,s,t) for (ll i = (ll)(s); i < (ll)(t); i++)
#define rep3(i,t) for (ll i = (ll)(1); i <= (ll)(t); i++)
#define rep4(i,s,t) for (ll i = (ll)(s); i <= (ll)(t); i++)
#define repr(i,t) for (ll i = (t-1); i>=(0);i--)
#define repr2(i,s,t) for (ll i = (t-1); i>=(s);i--)
#define repr3(i,t) for (ll i = (t); i>=(1);i--)
#define repr4(i,s,t) for (ll i = (t); i>=(s);i--)
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc =pair<char,char>;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using tuplis = array<ll,3>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
const ll LINF = 0x1fffffffffffffff;
const ll MINF = 0x7fffffffffff;
const int INF = 0x3fffffff;
const int mod=1000000007;
const int MODD=998244353;
const ld DINF = numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=acos(-1);
const ll dx[] ={0,1,0,-1,1,-1,1,-1};
const ll dy[] ={1,0,-1,0,1,1,-1,-1};
#define is_low(c) ('a'<=c)&&(c<='z')
#define is_upp(c) ('A'<=c)&&(c<='Z')
#define each1(i,a) for(auto&& i:a)
#define each2(x,y,a) for(auto&& [x,y]:a)
#define each3(x,y,z,a) for(auto&& [x,y,z]:a)
#define rrep(n) for(ll i=(n);i--;)
#define stlen(s) ll s.size()-1
#define all(v) begin(v), end(v)
#define range(v,a) begin(v),begin(v)+a
#define range2(v,a,b) begin(v)+a,begin(v)+b
#define range3(v,a) begin(v)+1,begin(v)+a+1
#define range4(v,a,b) begin(v)+a+1,begin(v)+b+1
#define allr(v) rbegin(v), v.rend(v)
#define ranger(v,a) rbegin(v),rbegin(v)+a
#define ranger2(v,a,b) rbegin(v)+a,rbegin(v)+b
#define ranger3(v,a) rbegin(v)+1,rbegin(v)+a+1
#define ranger4(v,a,b) rbegin(v)+a+1,rbegin(v)+b+1
#define cout(n) cout<<std::fixed<<std::setprecision(n)
//#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a)); a.erase(unique(all(a))),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size); in(name)
#define vv(type,name,h,...) vector<vector<type>> name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>> name(h,vector<type>(w)); in(name)
template<class T> auto min(const T& a){ return *min_element(all(a));}
template<class T> auto max(const T& a){ return *max_element(all(a));}
inline ll popcnt(ull a){return __builtin_popcountll(a);}
ll gcd(ll a,ll b){while(b){ll c=b; b=a%b;a=c;}return a;}
ll lcm(ll a,ll b){unless(a&&b) return 0;return a*b/gcd(a,b);}
ll intpow(ll a,ll b){ll ans=1; while(b){if(b&1)ans*=a;a *=a; b/=2;}return ans;}
ll modpow(ll a,ll b, ll p=mod){ll ans=1; while(b){if(b&1)(ans*=a)%=p;(a*=a)%=p;b/=2;}return ans;}
template<class T,class U> bool chmin(T& a,const U& b){if(a>b){a=b;return 1;}return 0;}
template<class T,class U> bool chmax(T& a,const U& b){if(a<b){a=b;return 1;}return 0;}
vector<ll> iota(ll n){vector<ll> a(n); iota(all(a),0);return a;}
vector<pll> factor(ull x){vector<pll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0){ans.push_back({i,1});while((x/=i)%i==0)ans.back().second++;}if(x!=1)ans.push_back({x,1});return ans;}
map<ll,ll> factor_map(ull x){map<ll,ll> ans; for(ull i=2; i*i<=x;i++)if(x%i==0){ans[i]=1;while((x/=i)%i==0)ans[i]++;}if(x!=1)ans[x]=1;return ans;}
vector<ll> divisor(ull x){vector<ll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0)ans.push_back(i);rrep(ans.size()-(ans.back()*ans.back()==x))ans.push_back(x/ans[i]);return ans;}
int scan() {return getchar();}
void scan(int &a){scanf("%d", &a);}
void scan(unsigned& a){scanf("%u",&a);}
void scan(long& a){scanf("%ld",&a);}
void scan(long long& a){scanf("%lld", &a);}
void scan(char& a){ do{a=getchar();}while(a==' '||a=='\n');}
void scan(float& a){ scanf("%f",&a);}
void scan(double& a){ scanf("%lf",&a);}
void scan(long double& a){ scanf("%Lf",&a);}
void scan(string& a){cin>> a;}
template<class T> void scan(vector<T>& a){for(auto&& i:a)scan(i);}
template<class T,size_t size> void scan(array<T, size>& a){for(auto&& i:a)scan(i);}
template<class T,class L> void scan(pair<T,L>&p){scan(p.first);scan(p.second);}
template<class T,size_t size> void scan(T (&a)[size]){ for(auto&& i:a)scan(i);}
void in(){}
template <class Head,class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
void print(){putchar(' ');}
void print(bool a){printf("%d", a);}
void print(int a){printf("%d",a);}
void print(unsigned a){ printf("%u",a);}
void print(long a){printf("%ld",a);}
void print(unsigned long long a){printf("%llu",a);}
void print(char a){ printf("%c",a);}
void print(double a){printf("%.15f",a);}
void print(long double a){printf("%.15Lf",a);}
void print(const string&a){for(auto&&i :a)print(i);}
template<class T> void print(const vector<T> &a){if(a.empty())return ;print(a[0]);for(auto i=a.begin();++i!=a.end();){putchar(' ');print(*i);}}
template<class T> void print(const deque<T>&a ){if(a.empty())return;print(a[0]);for(auto i=a.begin(); ++i!=a.end();){putchar(' ');print(*i);}}
template<class T, size_t size> void print(const T (&a)[size]){print(a[0]);for(auto i=a;++i!=end(a);){putchar(' ');print(*i);}}
template<class T> void print(const T& a){cout<<a;}
int out(){putchar('\n');return 0;}
template<class T> int out(const T& t){print(t);putchar('\n');return 0;}
template<class Head,class... Tail> int out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);return 0;}
int first(bool i){return out(i?"first":"second");}
int yes(bool i){return out(i?"yes":"no");}
int Yes(bool i){return out(i?"Yes":"No");}
int YES(bool i){return out(i?"YES":"NO");}
int possible(bool i){return out(i?"possible":"impossible");}
int Possible(bool i){return out(i?"Possible":"Impossible");}
int POSSIBLE(bool i){return out(i?"POSSIBLE":"IMPOSSIBLE");}

 
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
using mat = vector<vector<ll>>;
using vec = vector<ll>;

/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/

/* 4 方向への隣接頂点への移動を表すベクトル */



signed main(){


INT(N);
ll A[N];
rep(i,N)cin>>A[i];
sort(A,A+N);
ll ans1=0,ans2=0,ans3=0,ans4=0;
deque<ll> deq1,deq2,deq3,deq4,deq5,deq6;
rep(i,N)deq1.push_back(A[i]);
rep(i,N)deq2.push_front(A[i]);

if(N%2==1){
 



rep(i,N){
  if(i%4==0){
    ll v1=deq1.front();
    ll v2=deq2.front();
    deq1.pop_front();
    deq2.pop_front();
    deq3.push_front(v1);
    deq4.push_front(v2);
    deq5.push_front(v1);
    deq6.push_front(v2);
  }
  elif(i%4==1){
    ll v1=deq1.back();
    ll v2=deq2.back();
    deq1.pop_back();
    deq2.pop_back();
    deq3.push_back(v1);
    deq4.push_back(v2);
    deq5.push_front(v1);
    deq6.push_front(v2);
    
  }
  elif(i%4==2){
    ll v1=deq1.back();
    ll v2=deq2.back();
    deq1.pop_back();
    deq2.pop_back();
    deq3.push_front(v1);
    deq4.push_front(v2);
    deq5.push_back(v1);
    deq6.push_back(v2);
  }
  else{
    ll v1=deq1.front();
    ll v2=deq2.front();
    deq1.pop_front();
    deq2.pop_front();
    deq3.push_back(v1);
    deq4.push_back(v2);
    deq5.push_back(v1);
    deq6.push_back(v2);
  }




}
int pre1=deq3.front(),pre2=deq4.front(),pre3=deq5.front(),pre4=deq6.front();
deq3.pop_front();
deq4.pop_front();
deq5.pop_front();
deq6.pop_front();
rep(i,N-1){
  ll v3,v4,v5,v6;
  v3=deq3.front();
  v4=deq4.front();
  deq3.pop_front();
  deq4.pop_front();
  ans1+=abs(v3-pre1);
  ans2+=abs(v4-pre2);
  pre1=v3;
  pre2=v4;
  v5=deq5.front();
  v6=deq6.front();
  deq5.pop_front();
  deq6.pop_front();
  ans3+=abs(v5-pre3);
  ans4+=abs(v6-pre4);
  pre3=v5;
  pre4=v6;
}
}
else{
  rep(i,N){
  if(i%4==0){
    ll v1=deq1.front();
    ll v2=deq2.front();
    deq1.pop_front();
    deq2.pop_front();
    deq3.push_front(v1);
    deq4.push_front(v2);
    deq5.push_front(v1);
    deq6.push_front(v2);
  }
  elif(i%4==1){
    ll v1=deq1.back();
    ll v2=deq2.back();
    deq1.pop_back();
    deq2.pop_back();
    deq3.push_back(v1);
    deq4.push_back(v2);
    deq5.push_front(v1);
    deq6.push_front(v2);
    
  }
  elif(i%4==2){
    ll v1=deq1.back();
    ll v2=deq2.back();
    deq1.pop_back();
    deq2.pop_back();
    deq3.push_front(v1);
    deq4.push_front(v2);
    deq5.push_back(v1);
    deq6.push_back(v2);
  }
  else{
    ll v1=deq1.front();
    ll v2=deq2.front();
    deq1.pop_front();
    deq2.pop_front();
    deq3.push_back(v1);
    deq4.push_back(v2);
    deq5.push_back(v1);
    deq6.push_back(v2);
  }




}
int pre1=deq3.front(),pre2=deq4.front(),pre3=deq5.front(),pre4=deq6.front();
deq3.pop_front();
deq4.pop_front();
deq5.pop_front();
deq6.pop_front();
rep(i,N-1){
  ll v3,v4,v5,v6;
  v3=deq3.front();
  v4=deq4.front();
  deq3.pop_front();
  deq4.pop_front();
  ans1+=abs(v3-pre1);
  ans2+=abs(v4-pre2);
  pre1=v3;
  pre2=v4;
  v5=deq5.front();
  v6=deq6.front();
  deq5.pop_front();
  deq6.pop_front();
  ans3+=abs(v5-pre3);
  ans4+=abs(v6-pre4);
  pre3=v5;
  pre4=v6;
}


}
out(max(max(ans1,ans2),max(ans3,ans4)));





}