//#define _GLIBCXX_DEBUG
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);
int dx[9] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 1, 0, -1, 1, -1, -1, 1, 0};

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(15);

  ll N,X,M; cin>>N>>X>>M;
  
  ll s,roop;
  vector<ll> list(M,-1); list[X]=0;
  vector<ll> vec(1,X);
  for(int i=1;;i++){
    ll A=vec[i-1]*vec[i-1]%M;
    if(list[A]>-1) {s=list[A]; roop=i-s; break;}
    else{
      list[A]=i;
      vec.push_back(A);
    }
  }
  
  //rep(i,vec.size()) {if(i!=0) cout<<" "; cout<<vec.at(i);} cout<<'\n';
  
  ll sz=vec.size();
  ll ans=0;
  ll sum=0;
  for(int i=s;i<s+roop;i++) sum+=vec[i];
  rep(i,s) ans+=vec[i];
  N-=s;
  ans+=N/roop*sum;
  N%=roop;
  for(int i=s;i<s+N;i++) ans+=vec[i];
  
  cout<<ans<<'\n';
    
  
  return 0;
}
