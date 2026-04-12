#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int x;
  cin >> x;
  vector<int> vec = {3, 5, 7};
  if(find(vec.begin(), vec.end(), x) != vec.end()) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
