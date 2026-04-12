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
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int H,W;
  cin >> H >> W;
  v(string) G(H);
  rep(i,H) {
    cin >> G[i];
  }
  vv(bool) ok(H,v(bool)(W,true));
  rep(i,H) {
    bool a = true;
    rep(j,W) {
      if(G[i][j] == '#') a = false;
    }
    if(a) {
      rep(j,W) {
        ok[i][j] = false;
      }
    }
  }
  rep(j,W) {
    bool a = true;
    rep(i,H) {
      if(G[i][j] == '#') a = false;
    }
    if(a) {
      rep(i,H) {
        ok[i][j] = false;
      }
    }
  }
  rep(i,H) {
    bool h = false;
    rep(j,W) {
      if(ok[i][j]) {
        h = true;
        cout << G[i][j];
      }
    }
    if(h) cout << endl;
  }
  return 0;
}