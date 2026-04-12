#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<ll> A(N);
  ll as = 0;
  ll mod = 1e9+7;
  REP(i, N){
    cin >> A[i];
    as += A[i];
    as %= mod;
  }
  ll ans = 0;
  REP(i, N-1){
    as = as - A[i];
    if(as < 0){
      as += mod;
    }
    ans += A[i]*(as)%mod;
    ans %= mod;
  }
  cout << ans << endl;
}