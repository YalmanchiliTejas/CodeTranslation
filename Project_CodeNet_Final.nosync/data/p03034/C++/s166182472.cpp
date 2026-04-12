#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  ll ans = 0;
  REP(i,1,n-1){
    set<int> st;
    ll ret = 0;
    for(int j=0; j<n; j++){
      if(n-1-i*j < i) break;
      ret += a[i*j];
      ret += a[n-1-i*j];
      if(st.find(i*j)!=st.end() ) break;
      st.insert(i*j);
      if(st.find(n-1-i*j)!=st.end()) break;
      st.insert(n-1-i*j);
      ans = max(ans, ret);
    }
  }
  cout << ans << ln;
  return 0;
}