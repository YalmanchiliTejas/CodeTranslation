#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long H, W;
vector<vector<long long>> cost_map(1000+1, vector<long long>(1000+1, 0));

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;
  vector<long long> A(N), sum_A(N+1,0);
  long long a;
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  reverse(A.begin(), A.end());
  for(int i = 0; i < N; ++i) {
    sum_A[i+1] = sum_A[i] + A[i];
  }

  long long sum = 0;
  for(int i = 0; i < A.size()-1; ++i) {
    sum += (A[i+1]%MOD)*(sum_A[i+1]%MOD)%MOD;
    sum %= MOD;
  }

  cout << sum << endl;

  return 0;
}
