#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a;
  cin>>a;
  int b[200];
  int c=0;
  int d=0;
  for(int i=1;i<=a;i++){
      cin>>b[i];
      if(i==1){
       c++; 
       d=max(d,b[i]);
      }
      else{
       if(i==2){
           if(b[i-1]<=b[i]){
            c++; 
            d=max(d,b[i]);
           }
       }
       else{
        d=max(d,b[i]);
        if(d==b[i]){
         c++;   
        }
       }
      }
  }
  cout<<c<<endl;
}
