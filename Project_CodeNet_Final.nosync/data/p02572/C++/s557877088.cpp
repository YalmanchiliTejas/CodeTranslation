#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  long long ans = 0,tmp = 0;
  vector<long long> a(n),b(n + 1,0);
  for(int i = 0;i < n;i++){
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }
  for(int i = 1;i < n + 1;i++){
    tmp = (b[n] - b[i]) % MOD * a[i - 1] % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}
