#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); ++it)
#define dforn(i, n) for(ll i = ((ll) n) - 1; i >= 0; i--)
#define db(v) cerr << #v << " = " << v << endl
#define pb push_back
typedef long long ll;
const int MAXN = 55;

ll n, A[MAXN], K[MAXN], ans;

void decrease(){
  ll s = 0;
  forn(i, n){
    K[i] = A[i] / n;
    s += K[i];
  }
  forn(i, n){
    A[i] -= K[i] * n;
    A[i] += (s - K[i]);
  }
  ans += s;
  bool ok = true;
  forn(i, n){
    if(A[i] >= n){
      ok = false;
      break;
    }
  }
  if(ok){
    printf("%lld\n", ans);
    return;
  }
  else {
    decrease();
  }
}

int main() {
  scanf("%lld", &n);
  forn(i, n){
    scanf("%lld", &A[i]);
  }
  
  decrease();
  return 0;
}
