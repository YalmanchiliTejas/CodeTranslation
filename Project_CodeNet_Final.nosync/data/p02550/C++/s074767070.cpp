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
typedef pair<ll,ll> ii;

// E

ll bf(ll N, ll X, ll M) {
  vector<ll> A;
  A.pb(X);
  rep(i,N-1) {
    ll v = A.back();
    A.pb(((v%M)*(v%M))%M);
  }
  ll sum = 0;
  rep(i,(int)A.size()) {
    sum += A[i];
    cout << A[i] << endl;
  }
  cout << "%%" << endl;
  return sum;
}




void solve() {

}

const bool debug = 0;

int main() {
  ll N,X,M;
  cin >> N >> X >> M;

  vector<ll> vec;
  map<int,int> used;
  ll cur = X;
  vec.pb(cur);
  used[cur] = 0;

  int sp = -1;
  while(1) {
    ll nex = ( cur * cur ) % M;
    if( used.count(nex) ) {
      sp = used[nex];
      break;
    }
    used[nex] = (ll)vec.size();
    vec.pb(nex);
    cur = nex;
  }
  if( debug ) {
    cout << "* sp = " << sp << " (" << vec[sp] << ")" << endl;
    rep(i,(int)vec.size()) {
      cout << "  vec[" << i << "] = " << vec[i] << endl;
    }
  }

  if( N <= (int)vec.size() ) {
    ll ans = 0;
    rep(i,N) {
      ans += vec[i];
    }
    cout << ans << endl;
    if( debug ) {
      cout << "Answer: " << bf(N,X,M)  << endl;
    }
    return 0;
  }

  ll ans = 0;
  rep(i,sp) {
    ans += vec[i];
  }

  if( debug ) {
    cout << " default = " << ans << endl;
  }
  
  ll sum = 0;
  REP(i,sp,(int)vec.size()) sum += vec[i];

  if( debug ) {
    cout << "  sum = " << sum << endl;
  }

  ll rem = N - ( sp );
  if( debug ) {
    cout << "  rem = " << rem << endl;
  }
  ll loop_len = (ll)vec.size() - sp;
  ll cnt = rem / loop_len;
  ans += ( cnt * sum );

  rem = rem - cnt * loop_len;
  rep(i,rem) {
    ans += vec[sp+i];
  }

  if( debug ) cout << "? ";
  cout << ans << endl;
  if( debug ) {
    cout << "Answer: " << bf(N,X,M)  << endl;
  }


  
  
  return 0;
}
