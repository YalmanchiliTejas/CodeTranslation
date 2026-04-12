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
typedef pair<int,int> ii;

void solve() {

}

const ll mod = 1000000007LL;
  
int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  ll sum = 0;
  rep(i,n) {
    cin >> A[i];
    ( sum += A[i] ) %= mod;
  }
  ll ans = 0;
  for(int i=n-1;i>=1;--i) {
    sum -= A[i];
    while( sum < 0LL ) ( sum += mod ) %= mod;
    ( ans += ( ( sum * A[i] ) % mod ) ) %= mod;
  }
  cout << ans << endl;
  
  return 0;
}
