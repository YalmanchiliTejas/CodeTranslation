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

ll mod = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, x;
  cin >> n >> x;
  ll size[n + 1], full[n + 1];
  size[0] = 1, full[0] = 1;

  REP(i, n){
    size[i + 1] = 2 * size[i] + 3;
    full[i + 1] = 2 * full[i] + 1;
  }

  ll ans = 0;

  while(x > 0 && n > 0){
    if(x >= (size[n] + 1) / 2){
      x -= (size[n] + 1) / 2;
      ans += full[n - 1] + 1;
    }
    else x--;
    n--;
    if(n == 0 && x > 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
