#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long int ans = 0;
  int mod = 1000000007;
  long long int sum = 0;
  for(int i = 0; i < N; i++){
    long long int a;
    cin >> a;
    ans += (a * sum) % mod;
    sum += a;
    sum %= mod;
  }
  cout << ans % mod << endl;
  return 0;
}