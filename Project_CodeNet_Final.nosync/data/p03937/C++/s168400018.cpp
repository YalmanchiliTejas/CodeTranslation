#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
long long int gcd(long long int x, long long int y){
  return y!=0 ? gcd(y, x%y) : x;
}
long long int lcm(long long int x, long long int y){
  return x*y/gcd(x, y);
}
long long int factorial(long long int x){
  return x==0 ? 1 : x*factorial(x-1);
}
int main(){
  long long i, j, h, w, ct=-1, tmp=0;
  cin >> h >>w;
  char a[h][w];
  for(i=0; i<h; i++)
    for(j=0; j<w; j++)
      cin >> a[i][j];
  for(i=0; i<h; i++)
    for(j=0; j<w; j++){
      if(a[i][j]=='#'){
	if(i+j==ct+1&&(i==tmp+1||i==tmp)){
	  ct++;
	  tmp=i;
	}
	else{
	  cout << "Impossible";
	  return 0;
	}
      }
    }
  cout << "Possible";
  return 0;
}
