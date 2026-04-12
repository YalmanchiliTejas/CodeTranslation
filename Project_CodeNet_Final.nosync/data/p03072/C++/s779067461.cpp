#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> h(n);
  for (int i=0; i<n; i++){
    cin >> h.at(i);
  }
  
  int cnt = 0;
  int m_h = h.at(0);
  
  for (int i=0; i<n; i++){
    if (h.at(i) >= m_h){
      cnt++;
      m_h = h.at(i);
    }
  }
  
  cout << cnt << endl;
  
}
