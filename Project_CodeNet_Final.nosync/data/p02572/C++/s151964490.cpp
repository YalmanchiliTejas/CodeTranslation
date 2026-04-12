#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  cin >> a;
  int mod = 1000000007;
  long long sum = 0;
  vector<int> s(a);
  for (int i=0;i<a;i++){
    cin >> s.at(i);
    sum += s.at(i);
    sum %= mod;
  }
  long long ans =0;
  for (int i=0;i<a-1;i++){
    sum -= s.at(i);
    if (sum < 0) sum += mod;
    ans += s.at(i)*sum;
    ans %= mod;
  }
  cout << ans << endl;
}
