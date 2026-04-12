#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i=0 ; i<n ; i++)
    cin >> h.at(i);
  
  int ans = 1;
  for (int i=1 ; i<n ; i++){
    int a = 1;
    for (int j=0 ; j<i ; j++){
      if (h.at(j) > h.at(i)){
        a = 0;
        break;
      }
    }
    if (a == 0)
      continue;
    ans++;
  }
  
  cout << ans << endl;
}