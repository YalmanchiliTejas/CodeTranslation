#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
long long moda(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
  ll n;
  cin >> n;
  ll ansa = 0,ansb = 0;
  vector<ll>v(n);
  rep(i,n)cin >> v[i];
  rep(i,n){
    ansa += v[i];
    ansa %= INF;
  }
  ansa = ansa * ansa;
  ansa %= INF;
  rep(i,n){
    ansb += v[i] * v[i];
    ansb %= INF;
  }
  ll ans = moda((ansa % INF - ansb % INF),INF);
  ans %= INF;
  ans = ans * modinv(2,INF) % INF;
  cout << ans << endl;

  return 0;
}
