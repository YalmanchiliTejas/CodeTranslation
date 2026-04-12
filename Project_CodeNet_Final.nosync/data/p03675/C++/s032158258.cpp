#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


long long int a,b,c[200010],d[200010],ans =1,ant=1;

int main(){
  cin >> a ;
  
  for(int i=0;i<a;i++)
    cin >> c[i];
  
  if(a%2 ==0){
    
    for(int i=0;i<a;i++){
      if(i%2 ==0){
         d[(a+i)/2] = c[i];
      }
      else{
         d[(a-i)/2] = c[i];
      }
    }
    
  }
  
  else{
    
    for(int i=0;i<a;i++){
      if(i%2 == 0){
        d[(a-i)/2] = c[i];
                      
      }
      
      else{
         d[(a+i)/2] = c[i];
      }
    }
  }
  for(int i=0;i<a;i++)
  cout << d[i] <<" ";
  
  cout << endl;
}
      
      
 
   
