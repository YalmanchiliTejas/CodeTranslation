#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long ans = 0;
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    sum %= 1000000007;
  }
  for(int i = 0; i < n; i++){
    sum -= a[i];
    if(sum < 0) sum += 1000000007;
    ans += a[i] * sum;
    ans %= 1000000007;
  }
  cout << ans << endl;
}
