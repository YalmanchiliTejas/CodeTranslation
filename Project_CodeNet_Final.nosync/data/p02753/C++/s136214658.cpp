#include <bits/stdc++.h>

using namespace std;

int main(){
  string str;
  cin >> str;
  
  if(str.at(0) == str.at(1) && str.at(1) == str.at(2)){
  	cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  
  return 0;
}