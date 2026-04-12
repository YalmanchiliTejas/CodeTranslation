#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> color;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    auto itr = color.upper_bound(-a[i]);
    if(itr != color.end()) color.erase(color.find(*itr));
    color.insert(-a[i]);
  }
  cout << color.size() << endl;
  return 0;
}