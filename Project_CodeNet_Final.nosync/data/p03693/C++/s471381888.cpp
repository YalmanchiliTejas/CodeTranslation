#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b;
  cin >>r>>g>>b;
  
  int sum = 100*r+10*g+b;
  
  string ans;
  sum%4==0 ? ans="YES" : ans="NO";
  
  cout <<ans<< endl;
}
