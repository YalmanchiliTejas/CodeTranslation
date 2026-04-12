#include<bits/stdc++.h>
using namespace std;

#define N 200000
#define MOD 1000000007

int main() {

  int n, list[N];
  long long s = 0;
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>list[i];
    s += list[i];
  }

  long ans = 0;
  for (int i = 0; i < n; i++) {
    long long sum = (s - list[i]) % MOD;
    ans += list[i] * sum;
    ans %= MOD;
    s -= list[i];
  }

  cout<<ans<<endl;
  return 0;
}
