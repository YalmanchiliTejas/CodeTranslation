#include <bits/stdc++.h>
using namespace std;

int main() {
 long int A,B,C,X,Y; 
 cin >>A>>B>>C>>X>>Y;
  C*=2;
 long int ans;
  if(X>=Y){
  long int g,h,i;
  g=A*X+B*Y; h=C*X ;i=C*Y+A*(X-Y);
  ans=min(g,min(h,i));  
  
  }    
  else{
  long int g,h,i;
  g=A*X+B*Y; h=C*Y ;i=C*X+B*(Y-X);
  ans=min(g,min(h,i));  
  
  }   
 cout <<ans <<endl; 
  
}