#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll N,X,M;
  cin >> N >> X >> M;

  vector<int> id(M,-1);
  vector<int> A;
  int len = 0;
  ll total = 0;
  while(id.at(X) == -1){
    A.p_b(X);
    id.at(X) = len;
    len++;
    total += X;
    X = X * X % M;
  }

  int cycle_size = len - id.at(X);
  ll cycle_sum = 0;
  for(int i = id.at(X); i < len; i++) cycle_sum += A.at(i);

  ll ans = 0;
  if(N <= len){
    rep(i,N)  ans += A.at(i);
  }
  else{
    ans += total;
    N -= len;
    ans += cycle_sum * (N/cycle_size);
    N %= cycle_size;
    rep(i,N)  ans += A.at(id.at(X)+i);
  }
  cout << ans << endl;

  return 0;
}