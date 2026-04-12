#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  multiset<ll> tail;
  REP(i,n) tail.insert(-1);
  REP(i,n){
    auto ub = tail.lower_bound(a[i]);
    tail.erase(--ub);
    tail.insert(a[i]);
  }
  ll ans = n;
  auto it = tail.begin();
  while(it!=tail.end()){
    if(*it==-1) ans--;
    it++;
  }
  cout << ans << endl;
}

