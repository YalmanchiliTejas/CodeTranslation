#include <stdio.h>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

int main(){
  
  /* read input */
  int N;
  scanf("%d", &N); // read int
  
  /*solve problem*/
  if(N==7 || N==5 || N==3){
    printf("YES");
  }
  else
    printf("NO");
  
  return 0;
}
