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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  auto dp=vec(n,n,-INF);
  vector<ll>mx(n,-INF);
  ll mmx=0;
  {
    vector<ll>v(2);
    rep(i,0,2)cin>>v[i],v[i]--;
    dp[v[0]][v[1]]=0;
    mx[v[0]]=0;
    mx[v[1]]=0;
  }
  auto b=vec(n-1,3,0LL);
  rep(i,0,n-1){
    rep(j,0,3)cin>>b[i][j],b[i][j]--;
  }
  ll last;cin>>last;last--;
  ll add=0;
  rep(i,0,n-1){
    sort(ALL(b[i]));
    if(b[i][0]==b[i][2]){
      add++;
      continue;
    }
    queue<pair<P,ll>>que;
    rep(j,0,3){
      vector<ll>p;
      rep(o,0,3)if(o!=j)p.PB(b[i][o]);
      que.emplace(MP(p[0],p[1]),dp[b[i][j]][b[i][j]]+1);
    }
    rep(j,0,2){
      if(b[i][j]!=b[i][j+1])continue;
      ll t=2;if(j==1)t=0;
      //cout<<b[i][t] spa b[i][j]<<endl;
      rep(o,0,n)que.emplace(MP(b[i][t],o),max(dp[b[i][j]][o],dp[o][b[i][j]])+1);
    }
    rep(j,0,3)rep(o,j+1,3)que.emplace(MP(b[i][j],b[i][o]),mmx);
    rep(j,0,3)rep(o,0,n)que.emplace(MP(b[i][j],o),mx[o]);
    while(!que.empty()){
      auto p=que.front();
      //cout<<i spa p<<endl;
      que.pop();
      chmax(mmx,p.se);
      chmax(mx[p.fi.fi],p.se);
      chmax(mx[p.fi.se],p.se);
      chmax(dp[p.fi.fi][p.fi.se],p.se);
    }
  }
  //debug(dp,n,n);
  //cout<<add<<endl;
  rep(i,0,n)rep(j,0,n){
    chmax(res,dp[i][j]+add+(i==last&&j==last));
  }
  cout<<res<<endl;
  return 0;
}