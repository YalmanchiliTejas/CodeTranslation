#ifdef Nyan_Nyan
#pragma region template
#endif

#include <bits/stdc++.h>

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (ll)(a).size()
#define last(a) (a).at((ll)(a).size()-1)
#define rep(i,n) for(ll i=0,i##_len=(n);i<i##_len;i++)
#define brep(i,a,b) for(ll i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) ll i=(n);ll now=-1;while(i--&&(now++||1))
#define xrep(i,n) for(ll i=1,i##_len=(n);i<=i##_len;i++)
#define Yes(n) cout<<((n)?YES:NO)<<'\n'
#define co(n) cout<<(n)<<'\n'
#define Sort(v) sort(all(v))
#define rSort(v) sort(all(v),greater<typeof(v[0])>())
#define Rev(v) reverse(all(v))
#define Unique(v) (v).erase(unique(all(v)),(v).end())
#define eb emplace_back
#define fi first
#define se second

#ifdef ONLINE_JUDGE
#define here()
#define comment(msg)
#define observe(var)
#define local(x)
#define change(x,y) y
#else
#define here() printf("%s/%d: passed\n", __func__, __LINE__)
#define comment(msg) cout<<"{ "<<msg<< " }\n"
#define observe(var) cout<<"{ "<<#var<<" : "<<var<<" }\n"
#define local(x) x
#define change(x,y) x
#endif

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vbl = vector<bool>;
using vint = vector<int>;
using vvll = vector<vll>;
using vvbl = vector<vbl>;
using vdbl = vector<double>;
using vstr = vector<string>;
using vvint = vector<vint>;

constexpr int INF = 1e9;
constexpr ll LINF = 1e18;

// --- functions which take 1 argument --- //
static inline void ignore_ret(int x){x++;}
template<class T> inline int sgn(T x){return (x>0)-(x<0);}
template<class T> inline double rad_to_deg(T a){return a/180.0*M_PI;}
template<class T> inline double deg_to_rad(T a){return a/M_PI*180.0;}
template<class T> inline ll factorial(T n){if(n==0)return 1;ll r=1;for(T i=2;i<=n;i++)r*=i;return r;}
template<class T> inline map<T,T> factorize(T n){map<T,T>r;for(T i=2;i*i<=n;i++){while(n%i==0){r[i]++;n/=i;}}if(n!=1)r[n]=1;return r;}
template<class T> inline vector<T> divisor(T n){vector<T>r;for(T i=1;i*i<=n;i++){if(!(n%i)){r.eb(i);if(i*i!=n)r.eb(n/i);}}Sort(r);return r;}

// --- functions which take 2 arguments --- //
template<class T> inline bool chmax(T&a,const T&b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,const T&b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T nPr(T n,T k){if(n<k||n<0||k<0)return 0;T r=1;for(T i=n-k+1;i<=n;i++)r*=i;return r;}
template<class T> inline T nCr(T n,T k){if(n<k||n<0||k<0)return 0;T r=1;k=min(k,n-k);for(T i=n-k+1;i<=n;i++)r*=i;return r/factorial(k);}

// --- functions which take vector(s) as argument(s) --- //
template<class T> inline void print(T v){cout<<"[ ";for(auto x:v)cout<<x<<' ';cout<<"]\n";}
template<class T> inline void print_2d(vector<T>v){for(T x:v)print<T>(x);}
template<class T> inline void print_d(T v,string d){rep(i,sz(v)-1)cout<<v[i]<<d;cout<<last(v)<<'\n';}
template<class T> inline void print_2d_d(vector<T>v,string d){for(T x:v)print_d<T>(x,d);}
template<class T> inline bool in(T k,vector<T>v){return find(all(v),k)!=v.end();}
                  inline bool in(char k,string v){return find(all(v),k)!=v.end();}
template<class T> inline T min(vector<T>v){return *min_element(all(v));}
template<class T> inline T max(vector<T>v){return *max_element(all(v));}
template<class T> inline ll sum(T v){return reduce(all(v),0LL);}
template<class T> inline T gcd(vector<T>v){T r=v[0];brep(i,1,sz(v)-1)r=gcd(r,v[i]);return r;}
template<class T> inline T lcm(vector<T>v){T r=v[0];brep(i,1,sz(v)-1)r=lcm(r,v[i]);return r;}
template<class T> inline double abs(vector<T>v){return sqrt(reduce(all(v),0.0,[](T s,T v){return s+=v*v;}));}
template<class T> inline T vector_add(T u,T v){T r;rep(i,u.size())r.eb(u[i]+v[i]);return r;}
template<class T> inline T vector_subtract(T u,T v){T r;rep(i,u.size())r.eb(u[i]-v[i]);return r;}
template<class T> inline T dot_product(vector<T>u,vector<T>v){if(u.size()<v.size())return 0;T r=0;for(ll i=0;i<u.size();i++)r+=u[i]*v[i];return r;}
template<class T> inline T cross_product(T u,T v){T r(3);r[0]=u[1]*v[2]-u[2]*v[1];r[1]=u[2]*v[0]-u[0]*v[2];r[2]=u[0]*v[1]-u[1]*v[0];return r;}

// --- functions which take set as argument --- //
template<class T> inline T min(set<T>v){return *min_element(all(v));}
template<class T> inline T max(set<T>v){return *max_element(all(v));}
template<class T> inline T gcd(set<T>v){T r=0;for(T x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> inline T lcm(set<T>v){T r=0;for(T x:v)r=(r==0)?x:lcm(r,x);return r;}
template<class T> inline T min(unordered_set<T>v){return *min_element(all(v));}
template<class T> inline T max(unordered_set<T>v){return *max_element(all(v));}
template<class T> inline T gcd(unordered_set<T>v){T r=0;for(T x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> inline T lcm(unordered_set<T>v){T r=0;for(T x:v)r=(r==0)?x:lcm(r,x);return r;}

#ifdef Nyan_Nyan
#pragma endregion template
#endif

void solve(char c) {
  cout << (in(c, "aiueo") ? "vowel" : "consonant") << endl;
}

int main() {
  char c;
  cin >> c;
  solve(c);
  return 0;
}
