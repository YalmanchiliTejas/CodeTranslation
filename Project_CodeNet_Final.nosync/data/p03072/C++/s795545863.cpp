#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> data(25);
  
  int mounum = 0;
  int result = 1;
  int flag = 0;

  
    cin >> mounum;
    
  for (int r = 0; r < mounum; r++) {
    cin >> data.at(r);
  }
  
  
  for (int i = 1; i < mounum; i++) {
    for (int k = 0; k < i; k++) {
      if(data.at(k)>data.at(i)){
        flag = 3;
      }
    }
    if(flag==3){
      flag=0;
    }
    else if(flag==0){
      result++;
      flag = 0;
    }
  }
  
    cout << result << endl;
}
