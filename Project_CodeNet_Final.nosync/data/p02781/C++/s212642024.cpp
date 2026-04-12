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

string n;
int k;

#define MAX 200
ll nCk[MAX][MAX];
void makeC(){
  nCk[0][0] = 1;
  rep(i,MAX-1)rep(j,i+1){
    nCk[i+1][j] += nCk[i][j];
    if(j+1<MAX) nCk[i+1][j+1] += nCk[i][j];
  }
}

// 重複組み合わせ
// 異なるn個の要素の中から重複を許してr個選ぶ組み合わせ
long long nHr(int n,int r) {
  if( r < 0 ) return 1;
  return ( n == 0 && r == 0 ) ? 1 : nCk[n+r-1][r];
}


bool check(string s) {
  int cnt = 0;
  rep(i,(int)s.size()) {
    if( s[i] != '0' ) ++cnt;
  }
  return cnt == k;
}

ll bf() {
  ll maxi = atoll(n.c_str());
  int cnt = 0;
  rep(i,maxi+1) {
    if(check(to_string(i))) {
      ++cnt;
    }
  }
  return cnt;
}

ll count(int keta, string sm) {
  int m = atoi(sm.c_str());
  ll cnt = 0;
  rep(i,m+1) {
    string s = to_string(i);
    if( (int)s.size() != keta ) continue;
    bool skp = false;
    rep(j,(int)s.size()) if( s[j] == '0' ) { skp = true; break; }
    if( skp ) continue;
    ++cnt;
    //if( check(s) ) ++cnt;
  }
  return cnt;
}

ll fac(int j) {
  ll ret = 1;
  REP(i,1,j+1) {
    ret = ret * (ll)i;
  }
  return ret;
}

const bool debug = 1;

ll dp[110][4][2];
ll dbb() {
  memset(dp,0,sizeof dp);
  dp[0][0][0] = 1;
  rep(i,(int)n.size()) {
    rep(j,k+1) {
      rep(l,2) {
	ll &v = dp[i][j][l];
	if( v == 0 ) continue;
	rep(m,10) {
	  bool lt = l | ( m < n[i]-'0' );
	  int coef = ( m == 0 ) ? 0 : 1;
	  //if( !lt && ( j + coef ) > k ) continue;
	  if( !lt && n[i]-'0' < m ) continue;
	  if( j + coef > k ) continue;
	  dp[i+1][j+coef][lt] += v;
	}
      }
    }
  }
  return dp[(int)n.size()][k][0] + dp[(int)n.size()][k][1];
}

void solve() {
  cout << dbb() << endl;
  return;
  ll ans = 0;
  
  REP(i,1,(int)n.size()+1) {
    if( i < k ) continue;
    if( debug ) {
      cout << "** i = " << i << endl;
    }
    if( i == (int)n.size() ) {
      ll zr = i - k;
      ll ot = k - 1;
      ll tmp = dbb();
      if( debug ) {
	cout << "  eldora DP = " << tmp << endl;
      }
      ans += tmp;
      /*
      ll tmp = count(i,n) * nHr(i-1,min(zr,ot));
      if( debug ) {
	cout << "  count(" << i << "," << n << ") = " << count(i,n) << endl;
	cout << "  nHr = " << i-1 << "H" << min(zr,ot) << " = " << nHr(i-1,min(zr,ot)) << endl;
	cout << "  zr = " << zr << ", ot = " << ot << " ? i = " << i << " - " << k << " - 1 " << endl;
      }
      ans += tmp;
      */
    } else {
      if( i == k ) {
	ll tmp = 1;
	rep(j,k) tmp *= 9LL;
	ans += tmp;
      } else {
	//	ll zr = i - k - 1;
	//ll ot = k;
	ll zr = i - k;
	ll ot = k - 1;
	//ll tmp = count(i,string(i,'9')) * nHr(i-1,min(zr,ot));
	ll tmp = (ll)pow(9,k) * nHr(i-1,min(zr,ot));
	if( debug ) {
	  cout << "  count(" << i << "," << string(i,'9') << ") = " << count(i,string(i,'9')) << endl;
	  cout << "  nHr = " << i-1 << "H" << min(zr,ot) << " = " << nHr(i-1,min(zr,ot)) << endl;
      }
	ans += tmp;
      }
    }
    if( debug ) {
      cout << "** End - i = " << i << ", ans = " << ans << endl;
      puts("");
    }
  }
  cout << ans << endl;
}

int main() {
  makeC();
  cin >> n >> k;
  solve();
  return 0;
}
