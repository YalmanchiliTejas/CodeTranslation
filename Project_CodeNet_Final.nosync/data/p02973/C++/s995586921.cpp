#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1e18;
/* テンプレートここまで */

// int main() {
//   ll n; cin >> n;
//   vector<ll> a(n);
//   REP(i, n) cin >> a[i];
//   vector<int> b(n+1);
//   FOR(i, (n+1)/2, n+1) b[i] = a[i-1];

// }
typedef pair<ll,ll> P;

int main(){
  ll n; cin >> n;
  multiset<ll> st;
  REP(i, n) st.insert(-1);
  REP(i, n){
    ll a; cin >> a;
    auto lb = st.lower_bound(a);
    lb--;
    st.erase(lb);
    st.insert(a);
  }
  ll ans = 0;
  FOREACH(x,st){
    if(x!=-1) ans++;
  }
  cout << ans << endl;
}