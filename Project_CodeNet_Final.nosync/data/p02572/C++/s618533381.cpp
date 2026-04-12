#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    sum %= MOD;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++){
    sum -= a[i];
    if(sum < 0) sum += MOD;
    ans += a[i] * sum;
    ans %= MOD;
  }
  cout << ans << endl;
}