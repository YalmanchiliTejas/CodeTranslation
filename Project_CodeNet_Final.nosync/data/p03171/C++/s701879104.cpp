#include<bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll INF=(1LL<<62);
const ld pi=acosl((ld)-1);
const ll mod = 1000000007;
// const ll mod = 1234567;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
#define endn "\n"
#define TO_STRING(VariableName) # VariableName

template <typename T>ostream &operator<<(ostream &out,const vector<T> &v) {rep(i,(int)v.size()-1)cout<<v[i]<<" ";cout<<v[(int)v.size()-1];return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const map<T1, T2> &p) {out << "(" << p.first << ", " << p.second << ")";return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const pair<T1, T2> &p){out << "(" << p.first << ", " << p.second << ")";return out;}
template<class T>void debag(const T &obj){cout<<obj<<endl;}

ll dp(ll l,ll r,vector<vector<ll>>&dpv,ll &n,vector<ll>&a){
  if(dpv[l][r]!=-INF)return dpv[l][r];
  if(l==r)return dpv[l][r]=0;

  if((r-l)%2==n%2){
    return dpv[l][r]=max(dp(l+1,r,dpv,n,a)+a[l],dp(l,r-1,dpv,n,a)+a[r-1]);
  }else{
    return dpv[l][r]=min(dp(l+1,r,dpv,n,a)-a[l],dp(l,r-1,dpv,n,a)-a[r-1]);
  }
}

bool solve(){
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];

  vector<vector<ll>>dpv(n+1,vector<ll>(n+1,-INF));

  cout<<dp(0,n,dpv,n,a)<<endl;

  return false;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<fixed<<setprecision(30);
  solve();
}
