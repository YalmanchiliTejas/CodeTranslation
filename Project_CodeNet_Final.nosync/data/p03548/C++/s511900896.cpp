#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X, Y, Z;
  scanf("%d %d %d", &X, &Y, &Z);
  int one = Y + 2 * Z;
  int i = 0;
  int sum = 1;

  while(one + i* (Y + Z) <= X) {
    i++;
    sum++;
  } 
  printf("%d\n",i);
}