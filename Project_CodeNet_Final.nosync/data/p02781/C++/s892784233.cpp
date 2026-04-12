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
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  string s;
  cin >> s;
  int K;
  cin >> K;
  int N = sz(s);
  vvi dp(K+1,vi(2,0));
  dp[0][0] = 1;
  rep(ni,N) {
    vvi dp2(K+1,vi(2,0));
    int x = s[ni]-'0';
    rep(i,2) {
      rep(j,10) {
        rep(k,K+1) {
          int ni = i;
          if(i==0) {
            if(j > x) continue;
            if(j<x) ni++; 
          }
          int nk = k;
          if(j>0) nk++;
          if(nk>K) continue;
          dp2[nk][ni] += dp[k][i];
        }
      }
    }
    dp = dp2;
  }
  cout << dp[K][0] + dp[K][1] << endl;
  return 0;
}