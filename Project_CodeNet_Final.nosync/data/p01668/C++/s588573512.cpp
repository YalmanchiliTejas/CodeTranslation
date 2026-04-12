#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

string sub1(string s) {
  for (int i=s.size()-1; i>=0; --i) {
    if (s[i] == '0') s[i] = '9';
    else {
      s[i]--;
      break;
    }
  }
  return s;
}

const ll mod = 1e9+7;
inline void add(ll &a, ll b) {
  if (a == -1) a = 0;
  a += b;
  if (a > mod) a -= mod;
}

int *fail;

ll dp1[10001][501][2];
ll dp2[10001][2];

ll solve(const string &A, const string &C) {
  int n = A.size();
  int m = C.size();
  memset(dp1,0,sizeof(dp1));
  memset(dp2,0,sizeof(dp2));
  dp1[0][0][0] = 1;
  
  REP(i,n) {
    REP(ls,2) {
      // if (dp1[i][0][ls]) cout << i << " "  << " " << ls << " " << dp1[i][0][ls] << endl;
      REP(k,(ls?10:(A[i]-'0'+1))) {
        int nls = ls||k<A[i]-'0';
        char c = k+'0';
        add(dp2[i+1][nls], dp2[i][ls]);
        add(dp1[i+1][0][nls], dp1[i][0][ls]);
        
        REP(j,m) {
          if (C[j] == c) {
            if (j == m-1) {
              add(dp2[i+1][nls], dp1[i][j][ls]);
            } else {
              add(dp1[i+1][j+1][nls], dp1[i][j][ls]);
            }
          }
        }
      }
    }
  }
  ll ans = dp2[n][0];
  add(ans, dp2[n][1]);

  if (C == "0") {
    ll sum = 0;
    ll r = 10;
    REP(i,n-1) {
      add(sum, r);
      r = r*10 % mod;
    }
    ans = (ans - sum + mod) % mod;
  }
  
  return ans;
}


int main() {
  string A,B,C;
  while(cin >> A >> B >> C) {
    if (A == "0") {
      cout << solve(B,C) << endl;
    } else {
      ll ans = solve(B,C)-solve(sub1(A),C);
      ans = (ans+mod)%mod;
      cout << ans << endl;
    }
  }
}