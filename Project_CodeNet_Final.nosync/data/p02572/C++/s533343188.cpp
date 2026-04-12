#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N; cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  vector<ll> sums(N);
  sums[N - 1] = 0;
  for(int i = N - 2; i >= 0; i--) {
    sums[i] = (A[i + 1] + sums[i + 1]) % 1000000007;
  }
  //for(int i = 0; i < N; i++) cout << sums[i] << endl;
  ll cnt = 0;
  for(int i = 0; i < N; i++) {
    cnt += (sums[i] * A[i]) % 1000000007;
  }
  cnt %= 1000000007;
  cout << cnt << endl;
}