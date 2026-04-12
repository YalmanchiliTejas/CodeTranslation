#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

        
    
int main(){
  ll n; int x, m; cin >> n >> x >> m; set<ll> st;
  vector<ll> a; a.push_back(x); st.insert(x); int nyan;
  ll sum = x; ll now = x;
  if(n<101010){
    rep(i, n-1){
      now*=now; now%=m;
      sum+=now;
    }
    cout << sum << endl; return 0;
  }
  for(int i=1; i<101010; i++){
    a.push_back(a[i-1]*a[i-1]%m);
    if(st.count(a[i])){
      nyan = a[i]; break;
    }
    if(a[i]==0) break;
    st.insert(a[i]);
    sum+=a[i];
  }
  if(a[a.size()-1]==0){
    cout << sum << endl;  return 0;
  }
  a.pop_back(); int begin;
  rep(i, a.size()){
    if(a[i]==nyan) begin = i;
  }
  int syuki = a.size()-begin;
  ll ans = 0; ll ikkai = 0; ll sai = 0;
  for(int i=0; i<begin; i++){
    sai+=a[i];
  }
  for(int i=begin; i<a.size(); i++){
    ikkai+=a[i];
  }
  ans = sai+((n-begin)/syuki)*ikkai;
  for(int i=begin; i<begin+(n-begin)%syuki; i++){
    ans+=a[i];
  }
  cout << ans << endl;
}