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
  string N;
  cin >> N;
  int K;
  cin >> K;
  vi dp(K+1,0);
  int b = 0;
  rep(ni,sz(N)) {
    int x = N[ni]-'0';
    vi dp2(K+1,0);
    // ok -> 0
    rep(k,K+1) {
      dp2[k] += dp[k];
    }
    // ok -> 1~9
    rep(k,K) {
      dp2[k+1] += dp[k] * 9;
    }
    // ? -> 
    if(b <= K) {
      rep(n,10) {
        if(n < x) {
          if(n==0) {
            dp2[b] += 1;
          } else if(b+1 <= K) {
            dp2[b+1] += 1;
          }
        }
      }
      if(x > 0) {
        b++;
      }
    }
    dp = dp2;
  }
  int ans = dp[K];
  if(b == K) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}