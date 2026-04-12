#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool check = false;
  if(s.at(0) != s.at(1)){
    check = true;
  }
  if(s.at(2) != s.at(1)){
    check = true;
  }
  if(s.at(0) != s.at(2)){
    check = true;
  }
  if(check){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}