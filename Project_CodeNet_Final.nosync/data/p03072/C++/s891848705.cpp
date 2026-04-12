#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  
  int res = 0;
  for(int i = 0; i < n; ++i){
    bool check = true;
    for(int j = 0; j < i; ++j){
      if(h[j] > h[i]){
        check = false;
      }
    }
    if(check){
      ++res;
    }
  }
  
  cout << res << endl;
}