#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  vector<string> s(a);
  for(int i = 0;i<a;i++){
    cin >> s.at(i);
  }
  vector<bool> line(a,false);
  vector<bool> column(b,false);
  
  for(int i = 0;i<a;i++){
    for(int j = 0;j<b;j++){
      if(s.at(i).at(j) == '#'){
        line.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  for(int i = 0;i<a;i++){
    if(line.at(i)){
      for(int j = 0;j<b;j++){
        if(column.at(j)){
          cout << s.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}