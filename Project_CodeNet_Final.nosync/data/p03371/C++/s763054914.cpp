#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y,kekka = 0;
  cin >> a >> b >> c >> x >> y;
  if(b+a <= 2*c){
    kekka += (a+b)*min(x,y);
    if(x > y){
      kekka += a*(x-y);
    }
    else if(x < y){
      kekka += b*(y-x);
    }
  }
  else{
    kekka += 2*c*min(x,y);
    if(x > y){
      if(a <= 2*c){
        kekka += a*(x-y);
      }
      else{
        kekka += 2*(x-y)*c;
      }
    }
    else if(x < y){
      if(b <= 2*c){
        kekka += b*(y-x);
      }
      else{
        kekka += 2*c*(y-x);
      }
    }
  }
  cout << kekka << endl;
}