#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N+1, 0);
  int mod = 1000000007;
  ll ans=0;
  
  rep(i, N){
    cin >> A.at(i);
    B.at(i+1) = B.at(i) + A.at(i);
  }
  rep(i, N){
   ll sum = (B.at(N) - B.at(i+1)) % mod;
    
    ans += A.at(i) * sum;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}


