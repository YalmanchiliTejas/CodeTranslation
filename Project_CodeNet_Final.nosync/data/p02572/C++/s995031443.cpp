#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> Summ(N+1);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    Summ[i+1] = Summ[i] + A[i]; 
    Summ[i+1] %= MOD;
  }
  long long ans = 0;
  for(int i = 0; i < N; i++){
    ans += Summ[i] * A[i]; 
    ans %= MOD;
  }
  cout << ans <<endl;
}

