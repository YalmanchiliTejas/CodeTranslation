#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  
  int x,y,z ;
  cin >>x>>y>>z ;

  int ans = 0 ;
  int i=1;

  while(1){
      int haba = y*i+(i+1)*z ;
      if(haba>x) break ;
      else ans = i ;
      i++ ;
  }

  cout << ans << endl ;  
  
}