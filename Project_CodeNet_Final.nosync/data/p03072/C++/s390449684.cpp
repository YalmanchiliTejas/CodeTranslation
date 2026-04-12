#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  
  int ans = 1;
  for(int i = 1; i < n; i++) {
    int count = 0;
    for(int j = 0; j < i; j++) {
     if(h.at(j) <= h.at(i)) {
      count++;
     }
    }
    if(count == i) {
      ans++;
    }
  }
  
  cout << ans << endl;
}
