#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll ans;

bool step(vector<ll>& vec){

  int n;
  n = vec.size();
  ll max_val = 0;
  int ind = 0;
  rep(i, n){
    if(chmax(max_val, vec[i])){
      ind = i;
    }
  }

  ll cnt = vec[ind] / n;
  vec[ind] = vec[ind] % n;
  rep(i, n){
    if(i != ind){
      vec[i] += cnt;
    }
  }

  ans += cnt;

  bool ok = true;
  rep(i, n){
    if(vec[i] >= n){
      ok = false;
    }
  }
  return ok;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ans = 0;

  int N;
  cin >> N;
  vector<ll> a(N);
  ll max_val = 0;
  rep(i, N){
    cin >> a[i];
    chmax(max_val, a[i]);
  }

  if(max_val < N){
    cout << 0 << endl;
    return 0;
  }

  while(!step(a));

  cout << ans << endl;
  
  return 0;
}
