#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){

  int x, y, z, total, cnt=0;
  cin >> x >> y >> z;

  total=2*z;
  while(total<=x+1){
    total+=y;
     cnt++;
    if(total>x){
      cout << cnt-1 << endl;
      return 0;
    }
    total+=z;
    if(total>x){
      cout << cnt << endl;
      return 0;
    }
  }

  return 0;
}