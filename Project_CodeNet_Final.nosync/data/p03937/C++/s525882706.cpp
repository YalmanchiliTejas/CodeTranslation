#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
  int a,b,d;
 string c[10];
      
  cin >> a>>b;
   for(int i=0;i<a;i++){
    cin >>c[i];
   }
  
   for(int i=0;i<a;i++){
     
     for(int j=0;j<b;j++){
       
      
      if(c[i][j] == '#'){
         d ++;
      }
     }
   }
  if(d>a+b-1){
  cout << "Impossible" << endl;
}
  else{
    cout <<"Possible" << endl;
  }
}
         
       
