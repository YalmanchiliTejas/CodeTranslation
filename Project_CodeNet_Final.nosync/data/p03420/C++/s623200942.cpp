#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  ll ans = 0;
  for(ll i = K+1; i <= N; i++){
    if(K != 0){
      ans += (i-K)*((N+1)/i) + max(0LL, (N+1)%i-K);
    }else{
      ans += (i-K)*((N+1)/i) + max(0LL, (N+1)%i-K) - 1;
    }
  }
  cout << ans << endl;
}