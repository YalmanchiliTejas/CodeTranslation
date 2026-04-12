#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> h(n);
  
  for(int i = 0; i < n; i++){
    cin >> h.at(i);
  }
  
  int ans = 1;
  int m = h.at(0);
  
  for(int i = 0; i < n-1; i++){
    if(i==0){
      if(m<=h.at(1)){
        ans++;
        m = h.at(1);
      }
    }
    else{
      if(m<=h.at(i+1)){
        ans++;
        m = h.at(i+1);
      }
    }
  }
    
    cout << ans << endl;
}