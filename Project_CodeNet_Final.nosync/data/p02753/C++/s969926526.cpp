#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int main(){
  string S ;
  int ans = 1;
  cin >> S ;
  if((S == "AAA") || (S == "BBB")) ans = 0 ;
  if(ans){
    cout << "Yes" << endl ;
  }  
  else{
    cout << "No" << endl ;
  }  
  return 0 ;
}