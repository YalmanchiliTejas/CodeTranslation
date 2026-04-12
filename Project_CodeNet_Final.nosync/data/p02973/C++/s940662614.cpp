#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  reverse(a.begin(), a.end());
  
  vector<int> x;
  x.emplace_back(a.at(0));
  for(int i = 1; i < n; i++){
    if(x.back() <= a.at(i)) x.emplace_back(a.at(i));
    else *upper_bound(x.begin(), x.end(), a.at(i)) = a.at(i);
  }
  
  cout << x.size() << '\n';
}