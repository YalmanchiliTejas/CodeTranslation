#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
constexpr int INF = 1e9;
//constexpr ll INF = 1LL << 61;
//constexpr int mod = 1e9+7;
constexpr ll mod = 998244353;

int main(){
  ll X, M;
  ll N;
  cin >> N >> X >> M;
  vector<ll> A;
  vector<ll> sum(1, 0);
  map<ll, ll> mp;
  ll x = X;
  ll ans = 0;
  int roop = 1;
  while(N){
    if(mp[x]){
      ll add = sum[roop-1] - sum[mp[x]-1];
      int kukan = roop-1 - (mp[x]-1);
      ans += add * (N / kukan);
      N %= kukan;
      break;
    }
    ans += x;
    mp[x] = roop;
    A.push_back(x);
    sum.push_back(sum[roop-1] + x);
    N--;
    roop++;
    x = (x*x) % M;
  }
  REP(i, N){
    ans += x;
    x = (x*x) % M;
  }
  cout << ans << endl;
  return 0;
}
