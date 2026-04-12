//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template<typename T, typename F>
struct Doubling
{
  const ll LOG = 45;
  vector<vector<int>> nxt;
  vector<vector<T>> sum;
  F f;
  T iden;
  Doubling(int sz, T iden,F &f):iden(iden),f(f)
  { 
    nxt.assign(LOG, vector< int >(sz, -1));
    sum.assign(LOG, vector< T >(sz, iden));
  }

  void set_next(int k, int x){
    nxt[0][k] = x;
  }
  void set_val(int k, T x){
    sum[0][k] = x;
  }
  void build()
  {
    for(ll k = 0; k + 1 < LOG; k++) {
      for(ll i = 0; i < nxt[k].size(); i++) {
        if(nxt[k][i] == -1) nxt[k + 1][i] = -1;
        else{
          nxt[k + 1][i] = nxt[k][nxt[k][i]];
          sum[k + 1][i] = f(sum[k][i],sum[k][nxt[k][i]]);
        }
      }
    }
  }
  ll query(int k, ll t)//t個進んだ時のsum
  {
    T ret = iden;
    for(ll i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1){
        ret = f(ret, sum[i][k]);
        k = nxt[i][k];
      }
    }
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,x,m;cin>>n>>x>>m;
  ll sz=45;
  auto f=[&](ll x,ll y){
    return x+y;
  };
  Doubling<ll,decltype(f)> db(m,0,f);
  rep(i,0,m){
    ll nxt=(i*i)%m;
    db.set_next(i,nxt);
    db.set_val(i,i);
  }
  db.build();
  //rep(i,0,db.LOG)cout<<db.nxt[i][x] spa db.sum[i][x]<<endl;
  cout<<db.query(x,n)<<endl;
  return 0;
}