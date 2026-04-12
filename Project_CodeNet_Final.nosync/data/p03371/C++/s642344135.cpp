#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long i,j,k,a,b,c,x,y,sumc=0,sumx=0,sumy=0;
  cin >> a >> b >> c >> x >> y;
  
  while(a+b >= 2*c && sumx < x && sumy < y){
	sumc += 2*c;
    sumx += 1;
    sumy += 1;
  }
  while(a+b < 2*c && sumx < x && sumy < y){
	sumc += a+b;
    sumx += 1;
    sumy += 1;
  }
  
  while(sumx < x){
    if(a <= 2*c){
      sumc += a;
      sumx += 1;
    }
    if(a > 2*c){
      sumc += 2*c;
      sumx += 1;
    }
  }
  
  while(sumy < y){
    if(b <= 2*c){
      sumc += b;
      sumy += 1;
    }
    if(b > 2*c){
      sumc += 2*c;
      sumy += 1;
    }
  }
  
  cout << sumc << endl;
}