#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
const double pi = acos(-1);
const double EPS = 1e-10;

signed main(){
  int n;
  cin >> n;
  vi a(n),b(n);
  REP(i,n) cin >> a[i];
  sort(ALL(a));
  b = a;
  reverse(ALL(b));
  vi ans;
  int c;
  bool fl =false;
  int sz = (int)a.size();
  if(sz % 2 == 1){
    REP(i,sz/2 + 1) b.pop_back();
    REP(i,sz/2 ) a.pop_back();
    c = a.back();
    a.pop_back();
    if (b.back()-c >= c-a.back()) {
      ans.pb(c);
      fl = true;
    }
    REP(i,n-1){
      if (i % 2 == 0) {
        ans.pb(b.back());
        b.pop_back();
      } else {
        ans.pb(a[i/2]);
      }
    }
    if (!fl) {
      ans.pb(c);
    }
  } else{
    REP(i,sz/2){
      b.pop_back();
      a.pop_back();
    }
    ans.pb(a.back());
    REP(i,n-1){
      if (i % 2 == 0) {
        ans.pb(b[i/2]);
      } else {
        ans.pb(a[i/2]);
      }
    }
    ans.pb(b.back());
  }
  int sum = 0;
  FOR(i,1,(int)ans.size()) sum += abs(ans[i] - ans[i-1]);
  cout << sum << endl;
}