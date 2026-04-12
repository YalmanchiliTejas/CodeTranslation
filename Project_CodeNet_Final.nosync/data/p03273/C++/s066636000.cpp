#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  vector<string> data(a);
  for(int i = 0;i < a;i++){
    cin >> data[i];
  }
  
  vector<bool> as(a,false);
  vector<bool> bs(b,false);  
  for(int i = 0;i < a;i++){
    for(int j = 0;j < b;j++){
      if(data[i][j] == '#'){
        as[i] = true;
        bs[j] = true;
      }
    }
  }
  
  for(int i = 0;i < a;i++){
    if(as[i]){
      for(int j = 0;j < b;j++){
        if(bs[j]){
          cout << data[i][j];
        }
      }
      cout << endl;
    }
  }
  
}
  