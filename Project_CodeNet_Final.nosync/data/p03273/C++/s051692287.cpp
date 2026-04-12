#pragma region template
#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (int)(a).size()
#define last(a) (a).at((int)(a).size()-1)
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define brep(i,a,b) for(int i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) int i=(n);int now=-1;while(i--&&(now++||1))
#define xrep(i,n) for(int i=1,i##_len=(n);i<=i##_len;i++)
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
#define cprint(vec)
#define comment(msg)
#define observe(var)
#define local(x)
#define alter(x,y) y
#else
#define here() cerr<<__func__<<'/'<<__LINE__<<": passed\n"
#define cprint(vec) print_e(vec)
#define comment(msg) cerr<<"{ "<<msg<< " }\n"
#define observe(var) cerr<<"{ "<<#var<<" : "<<var<<" }\n"
#define local(x) x
#define alter(x,y) x
#endif

using namespace std;
using ll    = long long;
using ld    = long double;
using ull   = unsigned long long;
using vbl   = vector<bool>;
using dqbl  = deque<bool>;
using vint  = vector<int>;
using vll   = vector<long long>;
using vdbl  = vector<double>;
using vstr  = vector<string>;
using vvbl  = vector<vector<bool>>;
using vdqbl = vector<deque<bool>>;
using vvint = vector<vector<int>>;
using vvll  = vector<vector<long long>>;

constexpr int         INF   = 1e9;
constexpr long long   LINF  = 1e18;
constexpr double      EPS   = 1e-9;
constexpr long double LEPS  = 1e-18;

// --- functions which take 1 argument --- //
inline void ignore_ret(int x){x++;}
template<class T> inline int sgn(const T& x){return (x>0)-(x<0);}
template<class T> inline int digit(T x){int r=1;while((x/=10)>=1)r++;return r;}
template<class T> inline double deg_to_rad(const T& a){return a/180.0*M_PI;}
template<class T> inline double rad_to_deg(const T& a){return a/M_PI*180.0;}
template<class T> inline ll factorial(const T& n){if(n==0)return 1;ll r=1;brep(i,2,n)r*=i;return r;}
template<class T> inline map<T,T> factorize(T n){map<T,T>r;for(T i=2;i*i<=n;i++){while(n%i==0){r[i]++;n/=i;}}if(n!=1)r[n]=1;return r;}
template<class T> inline vector<T> divisor(const T& n){vector<T>r;for(T i=1;i*i<=n;i++){if(!(n%i)){r.eb(i);if(i*i!=n)r.eb(n/i);}}Sort(r);return r;}

// --- functions which take 2 arguments --- //
template<class T> inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T nPr(const T& n,const T& k){if(n<k||n<0||k<0)return 0;T r=1;brep(i,n-k+1,n)r*=i;return r;}
template<class T> inline T nCr(const T& n,const T& k){if(n<k||n<0||k<0)return 0;T r=1;k=min(k,n-k);brep(i,n-k+1,n)r*=i;return r/factorial(k);}

// --- functions which take vector(s) as argument(s) --- //
template<class T> inline void print(const vector<T>& v){cout<<"[ ";for(auto& x:v)cout<<x<<' ';cout<<"]\n";}
template<class T> inline void print(const vector<vector<T>>& v){for(auto& x:v)print<T>(x);}
template<class T> inline void print_d(const vector<T>& v,string d){rep(i,sz(v)-1)cout<<v[i]<<d;cout<<last(v)<<'\n';}
template<class T> inline void print_d(const vector<vector<T>>& v,string d){for(auto& x:v)print_d(x,d);}
template<class T> inline void print_e(const vector<T>& v){cerr<<"[ ";for(auto& x:v)cerr<<x<<' ';cerr<<"]\n";}
template<class T> inline void print_e(const vector<vector<T>>& v){for(auto& x:v)print_e<T>(x);}
template<class T> inline bool in(const T& k,const vector<T>& v){return find(all(v),k)!=v.end();}
                  inline bool in(const int& k,const vector<ll>& v){return find(all(v),k)!=v.end();}
                  inline bool in(const ll& k,const vector<int>& v){return find(all(v),k)!=v.end();}
                  inline bool in(const char& k,const string& v){return find(all(v),k)!=v.end();}
                  inline bool in(const char*& k,const vector<string>& v){return find(all(v),k)!=v.end();}
template<class T> inline T min(const vector<T>& v){return *min_element(all(v));}
template<class T> inline T max(const vector<T>& v){return *max_element(all(v));}
template<class T> inline T sum(const T& v){return reduce(all(v),(T)0);}
template<class T> inline T gcd(const vector<T>& v){T r=v[0];brep(i,1,sz(v)-1)r=gcd(r,v[i]);return r;}
template<class T> inline T lcm(const vector<T>& v){T r=v[0];brep(i,1,sz(v)-1)r=lcm(r,v[i]);return r;}
template<class T> inline double abs(const vector<T>& v){return sqrt(reduce(all(v),0.0,[](T s,T v){return s+=v*v;}));}
template<class T> inline T vector_add(const T& u,const T& v){T r(u.size());rep(i,u.size())r[i]=u[i]+v[i];return r;}
template<class T> inline T vector_subtract(const T& u,const T& v){T r(u.size());rep(i,u.size())r[i]=u[i]-v[i];return r;}
template<class T> inline T vector_multiply(const T& u,const T& v){T r(u.size());rep(i,u.size())r[i]=u[i]*v[i];return r;}
template<class S,class T> inline common_type<S,T> dot_product(const vector<S>& u,const vector<T>& v){T r=0;rep(i,u.size())r+=u[i]*v[i];return r;}
template<class S,class T> inline void sort_by_second(vector<pair<S,T>>& v){sort(all(v),[](auto& L,auto& R){return L.second<R.second;});}

// --- functions which take set/map as argument --- //
template<class T> inline bool in(const T& k,const set<T>& v){return find(all(v),k)!=v.end();}
template<class T> inline bool in(const T& k,const unordered_set<T>& v){return find(all(v),k)!=v.end();}
template<class T> inline T min(const set<T>& v){return *min_element(all(v));}
template<class T> inline T min(const unordered_set<T>& v){return *min_element(all(v));}
template<class T> inline T max(const set<T>& v){return *max_element(all(v));}
template<class T> inline T max(const unordered_set<T>& v){return *max_element(all(v));}
template<class T> inline T gcd(const set<T>& v){T r=0;for(T x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> inline T gcd(const unordered_set<T>& v){T r=0;for(T x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> inline T lcm(const set<T>& v){T r=0;for(T x:v)r=(r==0)?x:lcm(r,x);return r;}
template<class T> inline T lcm(const unordered_set<T>& v){T r=0;for(T x:v)r=(r==0)?x:lcm(r,x);return r;}
template<class T>         inline void print(const set<T>& v){cout<<"[ ";for(T& x:v)cout<<x<<' ';cout<<"]\n";}
template<class T>         inline void print(const unordered_set<T>& v){cout<<"[ ";for(T& x:v)cout<<x<<' ';cout<<"]\n";}
template<class S,class T> inline void print(const map<S,T>& m){cout<<"[ ";for(auto& x:m)cout<<"{ "<<x.fi<<", "<<x.se<<" } ";cout<<"]\n";}
template<class S,class T> inline void print(const unordered_map<S,T>& m){cout<<"[ ";for(auto& x:m)cout<<"{ "<<x.fi<<", "<<x.se<<" } ";cout<<"]\n";}
#pragma endregion template

int main() {
  int h, w;
  cin >> h >> w;

  vstr given(h);
  rep(i, h) cin >> given[i];

  vint columns_to_be_ignored;
  vint rows_to_be_ignored;

  rep(i, h) {
    if (given[i] == string(w, '.')) rows_to_be_ignored.eb(i);
  }

  rep(j, w) {
    bool flag = 1;
    rep (i, h) {
      if (given[i][j] == '#') {
        flag = 0;
        break;
      }
    }
    if (flag) columns_to_be_ignored.eb(j);
  }

  rep(i, h) {
    bool flag = 0;
    rep(j, w) {
      if (!in(i, rows_to_be_ignored) && !in(j, columns_to_be_ignored)) {
        cout << given[i][j];
        flag = 1;
      }
    }
    if (flag) cout << endl;
  }
  return 0;
}
