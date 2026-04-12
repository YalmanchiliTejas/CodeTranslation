#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
 long long int a,b[200010],c[200010];
  
  cin >> a;
  
  for(int i=0;i<a;i++)
    cin >> b[i];
  
  
  for(int i=0;i<a;i++){
    c[i] = b[i];
  }
  
  
  sort(b,b+a);
  
  
 
    if(b[(a/2)-1] == b[(a/2)]){
      for(int i=0;i<a;i++){
      cout << b[(a/2)-1] << endl;
      }
    }
  
  
    else{
      for(int i=0;i<a;i++){
      if(c[i] <= b[(a/2)-1]){
        
        cout << b[(a/2)] << endl;
      }
      
      else{
        cout << b[(a/2)-1] << endl;
      }
        
      }
    
  }
}
      
  
  
  
    
