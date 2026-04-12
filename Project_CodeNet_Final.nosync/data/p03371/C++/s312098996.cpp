#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,x,y;

int main(){
  int i=0,j=0,sum=0;
  cin >> a >> b >> c >> x >> y;
  if(a+b>c*2){
    while(min(x,y)>i){
      sum+=c*2;
      i++;
      j++;
    }
  }
  while(i<x){
    if(a>c*2){
      sum += c*2;
      i++;
    }
    else {
      sum += a;
      i++;
    }
  }
  while(j<y){
    if(b>c*2){
      sum += c*2;
      j++;
    }
    else {
      sum += b;
      j++;
    }
  }
  cout << sum << endl;
  
  

  return 0;
}
