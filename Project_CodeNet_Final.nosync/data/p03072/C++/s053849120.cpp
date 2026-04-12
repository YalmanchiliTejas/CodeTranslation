#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> mt(n);
  for ( int i = 0; i < n; i++) cin >> mt.at(i);
  
  int p = n;
  
  for (int i = 0; i < n;i++){
    bool ok = true;
    for (int j = 0; j <=i; j++){
      if(mt.at(j) > mt.at(i)){
        ok = false;
        break;
      }
    }
    if(!ok)p--;
  }
  cout << p << endl;
}