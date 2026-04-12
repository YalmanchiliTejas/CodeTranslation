#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

int main(void){
  int a, b, c;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  
  if ((a*100 + b*10 + c)%4==0) {
    printf("YES");
  }else{
    printf("NO");
  }

  return 0;
}
