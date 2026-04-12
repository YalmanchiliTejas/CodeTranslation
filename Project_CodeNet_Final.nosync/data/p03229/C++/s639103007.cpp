#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e09;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll a[n];
  REP(i, n) cin >> a[i];
  SORT(a, n);

  ll s1 = 0, s2 = 0;

  if(n % 2){
    REP(i, n / 2){
      s1 -= 2 * a[i];
      s2 += 2 * a[n - 1 - i];
    }
    REP(i, n / 2 - 1){
      s1 += 2 * a[n - 1 - i];
      s2 -= 2 * a[i];
    }
    s1 += (a[n / 2] + a[n / 2 + 1]);
    s2 -= (a[n / 2 - 1] + a[n / 2]);
  }
  else{
    REP(i, n / 2 - 1){
      s1 += 2 * a[n - 1 - i];
      s1 -= 2 * a[i];
    }
    s1 += (- a[n / 2 - 1] + a[n / 2]);
  }
  ll ans = max(s1, s2);
  cout << ans << endl;
}
