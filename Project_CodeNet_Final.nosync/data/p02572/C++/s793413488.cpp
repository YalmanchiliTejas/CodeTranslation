#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> A(N);
  /*
  rep(i,N) cin >> A[i];

  ll ans = 0;
  int mod = 1000000007;


  //累積和
  vector <ll> S(N);
  S.at(0) = A.at(0);
  for (int i = 1; i < N; i++){
    S.at(i) = (S.at(i - 1) + A.at(i)) % mod;
  }

  for (int i = 0; i < N - 1; i++){
    ans += (A.at(i) * (S.at(N - 1) - S.at(i)) % mod) % mod;
    ans %= mod;
  }

  cout << ans << endl;
*/

  vector <ll> B(N + 1, 0);  //累積和テーブル
  int mod = 1000000007;

  for (int i = 0; i < N; i++){
    cin >> A[i];
    B[i + 1] = B[i] + A[i];
  }

  ll ans = 0;

  //iについて全探索
  for (int i = 0; i < N; i++){
    //A[i+1] + ... + A[N]を求める
    ll sum = (B[N] - B[i + 1]) % mod;
    ans += A[i] * sum;
    ans %= mod;
  }
  cout << ans << endl;
}
