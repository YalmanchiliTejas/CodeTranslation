#include <bits/stdc++.h>
using namespace std;






int main(){
  

  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  

  int answer=0;
  
  if ((a+b)<=2*c){
    answer=a*x+b*y;
  }
  
  else {
    if (x>=y){
      answer=2*c*y+min(a,2*c)*(x-y);
    }
    else {
      answer=2*c*x+min(b,2*c)*(y-x);
    }
  }
  
  cout<<answer<<endl;
  


    
  
  
  
}