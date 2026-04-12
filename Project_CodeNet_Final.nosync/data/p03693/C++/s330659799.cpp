#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b;
  scanf("%d %d %d",&r,&g,&b);
  r = r * 100;
  g = g * 10;
  int sum = r + g + b;
  if(sum%4==0)
    printf("YES\n");
  else
    printf("NO\n");
  
  return 0;
}
