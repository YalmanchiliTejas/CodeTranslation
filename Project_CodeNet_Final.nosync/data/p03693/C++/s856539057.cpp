#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int r,g,b,sum;
  scanf("%d",&r);
  scanf("%d",&g);
  scanf("%d",&b);
  sum = r*100+g*10+b;
  if(sum%4==0){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}