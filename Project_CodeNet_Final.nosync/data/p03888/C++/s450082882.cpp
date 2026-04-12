#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int r1,r2;
  while(cin>>r1>>r2){
    double r3 = r1*r2*1.0/(r1+r2);
    printf("%.7f\n",r3);
    //cout<<r3<<endl;
  }
  return 0;
}