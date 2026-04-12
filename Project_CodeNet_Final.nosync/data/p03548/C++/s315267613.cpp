#include<iostream>
#include<cmath>

using namespace std;
int main(){
  unsigned int x,y,z;
  scanf("%d %d %d", &x, &y, &z);
  printf("%d", (x-z)/(y+z));

  return 0;
}