#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0,MAX = 0;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
    if(vec.at(i) >= MAX){
      ans++;
      MAX = vec.at(i);
    }
  }
  cout << ans << endl;
}
