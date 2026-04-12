#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;
void YesNo(bool j){cout << (j ? "Yes" : "No") << endl; return;}
void yesno(bool j){cout << (j ? "yes" : "no") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}


int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll b=a[1],c=0,d=a[0];
  if(n==2) {
    c=max(d,b);
      pt(c);
    return 0;
  }
  for(int i=2; i<n; i++) {
      if(i%2==0) {
          b=max(d,b);
          c+=a[i];
          d+=a[i];
      }
      else {
          c=max(b,c);
          b+=a[i];
      }
  }
  if(n%2==1) {
      c=max(c,b);
      pt(c);
  }
  if(n%2==0) {
    c=max(d,b);
      pt(c);
  }
  
  return 0;
}

