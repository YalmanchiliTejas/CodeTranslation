#include "bits/stdc++.h"
using namespace std;

int main(void){
 string str;
  cin >> str;
  if(str[0] == str[1] && str[1] == str[2]){
   cout << "No" << endl; 
  }
  else cout << "Yes" << endl;
  
  return 0;
}