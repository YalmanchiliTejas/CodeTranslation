#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int sum;//最終出力
  sum=a*x+b*y;
  
  int p;
  p=max(x,y);
  
  int high;//??
  high=max(a,b);
  
  int i,t;
  for(i=0;i<=p;i++){
   
    if(x-i<0){
      if(i>=p){
        t=c*i*2;
    sum=min(sum,t);
      continue;
              }
        
      t=b*(y-i)+c*i*2;
    sum=min(sum,t);
      continue;
    }
    
    else if(y-i<0){
      if(i>=p){
        t=c*i*2;
    sum=min(sum,t);
      continue;
              }
      
      t=a*(x-i)+c*i*2;
    sum=min(sum,t);
      continue;
    }
    
    else{
      
      if(i>=p){
        t=c*i*2;
    sum=min(sum,t);
      continue;
              }
    
    t=a*(x-i)+b*(y-i)+c*i*2;
    sum=min(sum,t);
      
    }
    
    
    
  }
  
  cout << sum << endl;
}
