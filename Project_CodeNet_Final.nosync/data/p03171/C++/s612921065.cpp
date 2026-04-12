#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
const double eps = 1e-10;
  
int main() {
  int N;
  cin >> N;
  auto isfst = [&](int l,int r) {
    return (l+N-r)&1;
  };
  vl A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vv(ll) dp(N,vl(N,0));
  drep(l,N) {
    rep(r,N) {
      if(l>r) continue;
      if(l==r) {
        if(isfst(l,r)) {
          dp[l][r] = A[l];
        } else {
          dp[l][r] = -A[l];
        }
        continue;
      }
      if(isfst(l,r)) {
        dp[l][r] = max(dp[l+1][r]+A[l],dp[l][r-1]+A[r]);
      } else {
        dp[l][r] = min(dp[l+1][r]-A[l],dp[l][r-1]-A[r]);
      }
    }
  }
  cout << dp[0][N-1] << endl;
  return 0;
}