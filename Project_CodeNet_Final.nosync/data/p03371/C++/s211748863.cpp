#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int a,b,c,x,y,min,i,t;
  cin>>a>>b>>c>>x>>y;
  min=a*x+b*y;
  for (i = 0; i <= max(x,y); i++) {
    if(x-i>=0 and y-i>=0){
      t=a*(x-i)+b*(y-i)+c*2*i;
    }else if(x-i<0){
      t=b*(y-i)+c*2*i;
    }else{
      t=a*(x-i)+c*2*i;
    }
    if(min>t){
      min=t;
    }
  }
  cout << min << endl;
}