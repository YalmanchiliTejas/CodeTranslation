#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int flag=0;
  if(s.at(0) == s.at(1)){
    if(s.at(1) == s.at(2)) flag = 1;
  }
  if(flag) cout << "No" << endl;
  else cout << "Yes" << endl;
       
}