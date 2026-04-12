#include <bits/stdc++.h>
using namespace std;
int main (){
  
  int n;
  cin >>n;
  int h[n];
  for(int i=0; i<n; i++) cin>>h[i];
  
  int ma=h[0],count=1;
  
  for(int i=1; i<n; i++){
   if(ma<=h[i]){
     ma=h[i]; count++;
   }
  }
  
  
  cout << count << endl;

}