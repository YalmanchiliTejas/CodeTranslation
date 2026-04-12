#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 998244353;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };


int main () {
  int N,S;cin>>N>>S;
  vector<int> a(N);
  rep(i,N) cin>>a[i];
  vector<ll> F(S+1,0),pre(S+1,0);
  ll ans = 0;
  rep(i,N) {
    pre[0] += 1;
    F = pre;
    rep(j,S+1) {
      if(j+a[i] <= S){
	F[j+a[i]] += pre[j];
	F[j+a[i]] %= MOD;
      }
    }
    pre = F;
    ans = (ans + F[S]) % MOD;
  }
  cout << ans << endl; 
}