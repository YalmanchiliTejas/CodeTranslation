#include<bits/stdc++.h>

using namespace std;

int main(){

  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  int val = 100 * r + 10 * g + b;
  if( val % 4 == 0 ) printf("YES\n");
  else printf("NO\n");
  return 0;
}