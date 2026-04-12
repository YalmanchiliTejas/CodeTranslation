#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t> a(n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  int64_t wa = 0;
  for (int i = 0; i < n - 1; i++){
    sum -= a.at(i);
    wa += a.at(i) * (sum % 1000000007);
    wa %= 1000000007;
  }
  cout << wa << endl;
}