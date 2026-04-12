#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  long long ans = 0;
  int k = n / 2;
  for(int i = 0; i < n; i++){
    if(i < k){
      if(i == k-1){
        if(n % 2 == 0) ans -= a.at(i);
        else ans -= a.at(i) * 2;
      }
      else ans -= a.at(i) * 2;
    }
    else if(i == k) ans += a.at(i);
    else if(n % 2 && i == k+1) ans += a.at(i);
    else ans += a.at(i) * 2;
  }
  long long ne = 0;
  k = (n+1) / 2;
  for(int i = 0; i < n; i++){
    if(i < k){
      if(i == k-1) ne -= a.at(i);
      else if(i == k-2){
        if(n % 2) ne -= a.at(i);
        else ne -= a.at(i) * 2;
      }
      else ne -= a.at(i) * 2;
    }
    else if(i == k){
      if(n % 2) ne += a.at(i) * 2;
      else ne += a.at(i);
    }
    else ne += a.at(i) * 2;
  }
  ans = max(ans, ne);
  
  cout << ans << endl;
}