#include<iostream>
using namespace std;

int main(){
  int a, b, c, x, y;
  int min, nmin;
  int i, j;

  cin >> a >> b >> c >> x >> y;

  min = a*x + b*y;

  if(x>=y){
    for(i=0; i<y; i++){
      nmin = a*(x-i) + b*(y-i) + c*2*i;
      if(min>nmin) min = nmin;
    }
    for(j=i; j<=x; j++){
      nmin = a*(x-j) + c*2*j;
      if(min>nmin) min = nmin;
    }
  }else{
    for(i=0; i<x; i++){
      nmin = a*(x-i) + b*(y-i) + c*2*i;
      if(min>nmin) min = nmin;
    }
    for(j=i; j<=y; j++){
      nmin = b*(y-j) + c*2*j;
      if(min>nmin) min = nmin;
    }
  }

  cout << min << "\n";

  return 0;
}
