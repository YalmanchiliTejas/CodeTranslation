#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

#define MAX 3010
int N,S,A[MAX];
const ll mod = 998244353LL;

ll dp[MAX][MAX][3];

ll f(int L,int R) {
  ll ret = 0;
  int len = R - L + 1;
  rep(i,(1<<len)) {
    int sum = 0;
    rep(j,len) {
      if( (i>>j) & 1 ) {
	sum += A[L+j];
      }
    }
    if( sum == S ) ++ret;
  }
  return ret;
}

ll bf() {
  ll ans = 0;
  rep(L,N) {
    REP(R,L,N) {
      ans += f(L,R);
    }
  }
  return ans;
}

void solve() {
  //cout << "Answer : " << bf() << endl;
  rep(i,N) dp[i][0][0] = 1LL;
  rep(i,N) {
    rep(j,S+1) {
      // use
      if( j + A[i] <= S ) {
	// t = 0
	( dp[i+1][j+A[i]][1] += dp[i][j][0] ) %= mod;
	// t = 1
	( dp[i+1][j+A[i]][1] += dp[i][j][1] ) %= mod;
	( dp[i+1][j+A[i]][2] += dp[i][j][1] ) %= mod;
	// t = 2
      }
      // dont
      // t = 0
      ( dp[i+1][j][1] += dp[i][j][0] ) %= mod;
      // t = 1
      ( dp[i+1][j][1] += dp[i][j][1] ) %= mod;
      ( dp[i+1][j][2] += dp[i][j][1] ) %= mod;
    }
    /*
    cout << "** (" << i << ") fin" << endl;
    rep(j,S+1) {
      rep(k,3) {
	if( dp[i+1][j][k] != 0 ) {
	  cout << "dp[" << i+1 << "][" << j << "][" << k << "] = " << dp[i+1][j][k] << endl;
	}
      }
    }
    */
  }
  ll ans = 0;
  rep(i,N) if( A[i] == S ) ++ans;
  REP(i,1,N+1) {
    ( ans += dp[i][S][2] ) %= mod;
    //cout << i << "-th: " << dp[i][S][2] << endl;
  }
  cout << ans << endl;
}

int main() {
  cin >> N >> S;
  rep(i,N) cin >> A[i];
  solve();
  return 0;
}
